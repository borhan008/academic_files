
A= rand(10,10)>0.5;

for i = 1: length(Comp07_09)
   Comp07_09(i,i)=0;
end

for i = 1: length(A)
    for j = i: length(A)
        A(i,j)=A(j,i)
    end
end

Count =0;

for i = 1: length(A)
   Nlist = find( A(:,i) > 0 )';
   for j = Nlist
        for k = Nlist
           
            if A(j,k)>0
                Count = Count+1; 
            end
        end
    end
    
end

Count = Count/2;

NODES=length(Diag07_09);
w=zeros(Cross0079,1);
for i=1:NODES
n = find(Diag07_09(i,:)+Diag07_09(:,i)');
n_e = 0;
l_n = length(n);
for j=1:l_n
[dummy,n_v,dummy2] = find(Diag07_09(n(j),:));
n_e = n_e + l_n + length(n_v) - length(union(n,n_v));
end;
if l_n>1
w(i) = n_e/(l_n*(l_n-1));
end;
cl=mean(w);
return
end





Count =0;

for i = 1: length(Cross0081)
   Nlist = find( Cross0081(:,i) > 0 )';
   for j = Nlist
        for k = Nlist
           
            if Cross0081(j,k)>0
                Count = Count+1; 
            end
        end
    end
    
end

Count = Count/2;

C=diag(A^3)/(sum(A).*(sum(A) - 1))

for i=1:99
    K=0;
    
    for j=i+1:100
    
            if(Cross071(i,j)~=0)
                K=K+1;
           
            end
    Cross072(1,i)=K;
            
    end
    
    
end


for i=1:100
    K=0;
    for j=1:145
        if D(1,j)==i
           K=K+1;
        end
    end
    dist2(1,i)=K;
end


[pdf11,X11]= hist(G,50);
pdf11 = pdf11/sum(pdf11);

plot(X11,pdf11)

for i=1:185
    K=0;
    for j=1:377
        if AA(1,j)==i
           K=K+1;
        end
    end
    dist1(1,i)=K;
end





clustering coefficient:

TEST_FULL_SPARAE=1;
nodes_attribute=1;
if nodes_attribute==1
    if TEST_FULL_SPARAE==1
        Node_CC=zeros(31,1);
    elseif TEST_FULL_SPARAE==2
        Nodes_CC=sparse(31,1);
    end
    
    for i=1:31
        triangle_num=0;
        Neighbor=find(Adj_1(i,:)>0);
        node_degree=nnz(Neighbor);
        if node_degree==0||node_degree==1
            Node_CC(i)=0;              
        else
            triple_num=node_degree*(node_degree-1)/2;
            for j=1:(node_degree-1)
                for k=(j+1):node_degree
                    if Adj_1(Neighbor(j),Neighbor(k))>0
                        triangle_num=triangle_num+1;
                    end
                end
            end
            Node_CC(i)=triangle_num/triple_num;
        end        
    end   
    cc=sum(Node_CC)/31;
end

return

dlmwrite('adj_before1.txt',adj_before1,'delimiter','\t');

Code for component number:

L = sparse(diag(sum(Adjmat01))-Adjmat01);
rcm = symrcm(L);
 Lp = L(rcm, rcm);
 s = sum(tril(Lp), 2);
 cut = find(s == 0);

dlmwrite('Diameter2012.txt',Diameter2012,'delimiter','\t');

for i=1:100
Cross07(i,i)=0;
end

[pdf4,X4]= hist(Eigenvalue06,100);
pdf4 = pdf4/sum(pdf4);
plot(X4,pdf4)
for i=1:100
Crossavg06(i)=sum(abs(Cross06(i,:)))/99
end

dlmwrite('Component_No06_07.txt',Component_No06_07,'delimiter','\t');
dlmwrite('Component_No07_09.txt',Component_No07_09,'delimiter','\t');

dlmwrite('RetunUSA.txt',RetunUSA,'delimiter','\t');

dlmwrite('indices.txt',indices,'delimiter','\t');
dlmwrite('Degree06_07.txt',Degree06_07,'delimiter','\t');
dlmwrite('Adj_beforefirst.txt',Adj_beforefirst,'delimiter','\t');



for i=1:200
    k=0;
    if cut==i
        k=k+1;
    end 
end


[pdf12,X12]= hist(MeanCrosstest061,100);
pdf12 = pdf12/sum(pdf12);
cdf12 = 1-cumsum(pdf12);
plot(X12,cdf12)
plot(X12,cdf12,'o')
dlmwrite('cdf2.txt',cdf2,'delimiter','\t');
for meandegree:
    make adjacency matrix by making diagonal 0
    A(i,j)>=0.5
    then mean(sum(A));
   
    
    L = sparse(diag(sum(Adjmat03))-Adjmat03);
  rcm = symrcm(L);
  Lp = L(rcm, rcm);
  s = sum(tril(Lp), 2);
  cut = find(s == 0);

    
    for i=1:200
    K=0;
    for j=1:200
        if cut(j,1)==i
           K=K+1;
        end
    end
    dist1(1,i)=K;
end
   degree distribution:
  
   for i=1:97
    K=0;
    for j=1:97
        if CC(1,j)==i
           K=K+1;
        end
    end
    dist3(1,i)=K;
   end

   [pdf12,X12]= hist(dist1,50);
pdf12 = pdf12/sum(pdf12);
cdf12 = 1-cumsum(pdf12);

plot(log(X12),log(cdf12),'o')  
