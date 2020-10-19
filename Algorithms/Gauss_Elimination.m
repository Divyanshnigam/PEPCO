function [time,x] =Gauss_Elimination(A,B,n)
% elimination
time=clock;
Aug =[A,B];
clear A B
for col = 1:n-1
    for row =( col+1):n
        Aug(row,col:n+1) = Aug(row,col:n+1)- (Aug(col,col:n+1)*Aug(row,col))/Aug(col,col);
    end
end
clear row col;
% back sustitution
x = zeros(n,1);
x(n) = Aug(n,n+1)/Aug(n,n);
for i = (n-1):-1:1
    x(i) = (Aug(i,n+1)-(Aug(i,(i+1):n)*x((i+1):n)))/Aug(i,i); % back sustitution
end
% disp("roots From Gauss_elimination_method")
% x'
time=etime(clock,time);
end