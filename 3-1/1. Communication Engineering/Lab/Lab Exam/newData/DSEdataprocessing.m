[rownum colnum]= size(Global88);
for i=1:rownum
    for j=1:colnum
        if(Global88(i,j)==0)
            Global88(i,j)=Global88(i-1,j);
        end
    end
end

dlmwrite('Meanoccupation2007.txt',Meanoccupation2007,'delimiter','\t');

[rownum colnum]= size(Kospi_all);
for i=1:rownum-1
    for j=1:colnum
        
        retun_test7(i,j)=log(Kospi_all(i+1,j))-log(Kospi_all(i,j));
        
    end
end


 n = size (d,1); %Number of vertices
    for i=1:n
        for j=1:n
            d(i,j)=sqrt(2*(1-(d(i,j)))); %make distance matrix
        end
    end
    
    
    
    
    
    for i=1:36
        for j=1:36
            if (Cross_glo_bef(i,j)>=0.4554)
                Cross_11(i,j)=Cross_glo_bef(i,j);
            end
        end
    end
    
    
    
  for j=1:32
H=result*A(:,j+1)
  end
   result=A(:,j)*A(:,j+1) 
    
   
   Inverse participation ratio:
   
    
    
    
    
    
    
   for i=1:258
       for j=1:31
           if(C1(i,j)>0)
               C1(i,j)=1;
           end
       end
   end
   
   
   
   for i=1:258
       for j=1:31
           if(C1(i,j)<0)
               C1(i,j)=-1;
           end
       end
   end
   
   
   
   for i=1:257
        E(i,1)=sum(C1(i,:).*C1(i+1,:));
    end
   
   
   
   
   
   for i=1:221
       if(E2(i,1)<0)
           E2(i,1)=0;
       end
   end
   
   Energy:
   
   for i=1:3
       for j=1:2
        B(i,j)=A(i,j)*A(i,j+1);
       C(i,1)=sum(B(i,:));
       
       end
       
   end
           
   
   for i=1:10
       retun1=retun_test(:,1:20*i);
       Cross1=corrcoef(retun1);
       [u1,v1]=eigs(Cross1,1,'lm');
       N=20*i;
       D(i)=v1/N;
   end
   
   
   for i=1:10
       retun2=retun_test1(:,1:20*i);
       Cross2=corrcoef(retun2);
       [u2,v2]=eigs(Cross2,1,'lm');
       N=20*i;
       C(i)=v2;
   end
   
   
   for i=1:10
       retun4=retun_test4(:,1:20*i);
       Cross4=corrcoef(retun4);
       [u4,v4]=eigs(Cross4,1,'lm');
       N=20*i;
       E(i)=v4;
   end
   
   
   for i=1:10
       retun5=retun_test5(:,1:20*i);
       Cross5=corrcoef(retun5);
       [u5,v5]=eigs(Cross5,1,'lm');
       N=20*i;
       F(i)=v5;
   end
   
   
   
   for i=1:10
       retun7=retun_test7(:,1:20*i);
       Cross7=corrcoef(retun7);
       [u7,v7]=eigs(Cross7,1,'lm');
       N=20*i;
       VUSA2010(i)=v7/N;
   end
   
   
   for i=1:10
       retun6=retun_test6(:,1:20*i);
       Cross6=corrcoef(retun6);
       Mean1=mean(mean(Cross6));
       AVE1(i)=Mean1;
   end
   
   for i=1:10
       retun6=retun_test6(:,1:20*i);
       Cross6=corrcoef(retun6);
       [u6,v6]=eigs(Cross6,1,'lm');
       N=20*i;
       DSE2010(i)=v6/N;
   end
   
    for i=1:15
       retun=retunallcrisis(258*(i-1)+1:258*i,:);
       Cross=corrcoef(retun);
       a=Cross;
       for j=1:30
           a(j,j)=0;
       end
        Mean(i)=2*sum(sum(a))/(30*29);   
       Vola=mean(mean(abs(retun)));
       Ave(i)=Vola;
    end
   dlmwrite(sprintf('retun%d.txt',i),retun,'delimiter','\t');
   end
   
   
   
   
 files = dir ('*.txt');
f_len = length(files);
eval (['load ' files(1).name]);
name1 = files(1).name(1:end-4);
eval (['All=' name1]);
f_Alen = length(All);


for k = 1: f_len 
    
    eval (['load ' files(k).name]);
	name = files(k).name(1:end-4);
	eval (['a=' name]);
	f_prlen = length(a);  

   
   
   
   for i=1:4
       retun_all=AA(:,30*(i-1)+1:30*i);
       Cross6=corrcoef(retun_all);
       [u6,v6]=eigs(Cross6,2,'lm');
    
       VVV5(i)=v6(2,2);
       
   end
       
    dlmwrite(sprintf('VVV%d.txt',k),VVV,'delimiter','\t');
   end
   end
end
   
   VV(i)=V;
    end
       Ave=mean(VV); 
   end
   
   DSE2010(i)=sum(v6)/5;
   
   
   
   for i=1:15
       retun_all=retunallcrisis(258*(i-1)+1:258*i,:);
       Cross6=corrcoef(retun_all);
       [u6,v6]=eigs(Cross6,2,'lm');
    
       VVV4(i)=v6(2,2);
       
   end
    
   
   
   
   for i=1:12
       retun0=retun_forteen(21*(i-1)+1:21*i,:);
      dlmwrite(sprintf('retun0%d.txt',i),retun0,'delimiter','\t');  
    end
  
  
   
   
   
  
   
   
   
   
        