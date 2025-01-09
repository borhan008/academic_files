load Final_RAWALLDATA.txt
RAWDATA=Final_RAWALLDATA;
[rownum colnum]= size(RAWDATA);
for i=1:rownum-1
for j=1:colnum
Retun(i,j)=log(RAWDATA(i+1,j))-log(RAWDATA(i,j));
end
end


for s=1:30
    for l=1:100
       Retun= Retun(:,randperm(size(Retun,2))); 
    retun_all=Retun(125*(s-1)+1:125*s,1:100);
   Cross0=corrcoef(retun_all);
   for k=1:100
       Cross0(k,k)=0;
   end
            BB=tril(Cross0);
    
            Cross1(l)=2*sum(sum(BB))/(100*(99));
    end
   Ave(s)=mean(Cross1);
end