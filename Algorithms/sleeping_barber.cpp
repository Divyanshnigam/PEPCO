#include <stdio.h> // Kütüphanelerimiz
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <locale.h>

#define CLIENT_COUNT 10     // (Ön iþlemci direktiflerimiz) Müþteri sayýmýz
#define SHAVING_TIME 2  // Traþ bekleme süremiz

int armchairCount = 0;     // Deðiþkenlerimiz
int clientCount = 0;
int chairCount = 0;
int freechairCount = 0;
int serveClient = 0;
int sitChair = 0;

int* armchair;

sem_t barbers_sem;  // Semaforlarýmýz.
sem_t clients_sem;
sem_t mutex_sem;

void Barber(void* num)
{
	setlocale(LC_ALL,"Turkish"); //Türkçe karakter izni.
    int barberId = *(int*)num +1; // Burada barberId parametre olarak atanýr.
    int nextClient, clientId;

    printf("%d. Berber dükkana geldi.\n\n",barberId); // Berber salona giriþ yapar.

    while(1)    // Sonsuz döngü içerisinde dükkanda müþteri var mý yok mu kontrolü.
    {
        if (!clientId)
        {
            printf("%d. Berber uyumaya gitti.\n\n", barberId);     // Eðer salonumuzda müþteri yok ise berber uykuya geçer.
        }
        sem_wait(&barbers_sem);     // Müþteri olmadýðýndan koltuklara eriþim engellenir.
        sem_wait(&mutex_sem);

        serveClient = (++serveClient) % chairCount;  // Bekleyen müþterilerden birine, traþ olacak müþteri olarak atanýr.
        nextClient = serveClient;
        clientId = armchair[nextClient];
        armchair[nextClient] = pthread_self();

        sem_post(&mutex_sem);   // Traþ olacak müþteri için sandalyeye eriþim açýlýr ve berber müþteriyi traþ etmeye baþlar.
        sem_post(&clients_sem);

        printf("%d. Berber %d. müþteriyi traþ etmeye baþladý.\n\n", barberId, clientId);   // Berber müþteriyi traþ eder ve traþ iþlemini bitirir.
        sleep(SHAVING_TIME);
        printf("%d. Berber %d. müþterinin traþ iþlemini bitirdi.\n\n",barberId, clientId);
    }
    pthread_exit(0);
}

void Client(void* num)
{
	setlocale(LC_ALL,"Turkish"); //Türkçe karakter izni.
    int n = *(int*)num +1; // Burada client_id parametre olarak atanýr.
    int seatedChair, barber_identity;

    sem_wait(&mutex_sem);   // Koltuða eriþim kitlenir.

    printf("%d. Müþteri salona geldi.\n", n);      // Dükkana gelen müþteriler ekranda gösterilir.

    if (freechairCount > 0)
    {
        freechairCount--;     //Dükkana müþteri geldiði için, boþ sandalye sayýsý 1 eksilir.

        printf("%d. Müþteri bekleme koltuðuna alýndý.\n\n", n); // Müþterinin beklemesi ekranda gösterilir.

        sitChair = (++sitChair) % chairCount; // Müþteri bekleme koltuklarýndan boþ olaný seçip oturur.
        seatedChair = sitChair;
        armchair[seatedChair] = n;     

        sem_post(&mutex_sem);
        sem_post(&barbers_sem);	// Berber uyandýrýlýr.
                                    // Müþteri sandalyeye geçiceði zaman traþ koltuðuna olan eriþim kaldýrýlýr. Müþteri bu sayede traþ koltuðuna geçer
        sem_wait(&clients_sem);	// Bekleyen müþteri kuyruða katýlýr.
        sem_wait(&mutex_sem);

        barber_identity = armchair[seatedChair];    // Berber koltuða geçer.
        freechairCount++; // Boþ sandalye sayýsý 1 arttýrýlýyor.

        sem_post(&mutex_sem);
    }
    else
    {
        sem_post(&mutex_sem);
        printf("%d. Müþteri salona geldi fakat salon dolu olduðundan müþteri salondan ayrýldý.\n\n", n);  // Eðer dükkanda boþ sandalye yok ise, gelen müþteri içeri girmeden dükkandan ayrýlýr.
    }
    pthread_exit(0);
}

void Wait() // Traþ süreleri sonunda berberin dükkandan çýkmasý için yazýlmýþtýr.
{
    srand((unsigned int)time(NULL));
    usleep(rand() % (250000 - 50000 +1) + 50000);
}

int main (int argc, char** args)
{
	setlocale(LC_ALL,"Turkish"); //Türkçe karakter izni.
    printf("Müþteri sayýsýný giriniz : ");   // Dükkana gelicek müþteri sayýsý alýnýr.
    scanf("%d", &clientCount);

    printf("Dükkanda bulunan koltuk sayýsýný giriniz : "); // Dükkanda olan koltuk sayýsý alýnýr.
    scanf("%d", &chairCount);

    printf("Berber sayýsýný giriniz : "); // Dükkanda çalýþan berber sayýsý alýnýr.
    scanf("%d", &armchairCount);

    freechairCount = chairCount;
    armchair = (int*) malloc(sizeof(int) * chairCount);    // Verilen parametreler sayesinde dükkanda sandalyelerimizi oluþturuyoruz.

    if (clientCount > CLIENT_COUNT)
    {
        printf("\nMüþteri limiti : %d\n\n", CLIENT_COUNT);
        return EXIT_FAILURE;
    }

    pthread_t barber[armchairCount], client[clientCount];     // Verilen berber ve müþteri deðiþkenlerine göre thread'lerimizi tanýmlýyoruz.

    sem_init(&barbers_sem, 0, 0);   // Semaforlarýmýzý baþlatýyoruz.
    sem_init(&clients_sem, 0, 0);
    sem_init(&mutex_sem,0, 1);

    printf("\n\nBerber Salonu Açýldý.\n\n");
	int i;
    for(i = 0; i < armchairCount; i++)
    {
        pthread_create(&barber[i], NULL, (void*)Barber, (void*)&i);     // Verilen berber ve müþteri deðiþkenlerine göre thread'ler oluþturulur.
        sleep(1);
    }

    for(i = 0; i < clientCount; i++)
    {
        pthread_create(&client[i], NULL, (void*)Client, (void*)&i);
        Wait();
    }

    for(i = 0; i < clientCount; i++)
    {
        pthread_join(client[i], NULL);
    }

    printf("\n\nTüm müþterilerin traþ iþlemi bitti. Berber Salonu Kapatýlýyor...!\n\n");  // Tüm traþ iþlemlerinin sonucu berberler dükkandan ayýlýr ve salon kapatýlýr.

    return EXIT_SUCCESS;
}