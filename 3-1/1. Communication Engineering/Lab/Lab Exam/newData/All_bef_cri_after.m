data = [All_yearkospi(:,1) All_yearkospi(:,2) All_yearkospi(:,3)];
data3=sortrows(data,2); 

Cname=data3(1,2);
EaCoDaLength = [];
count =1;
for i =2: length(data3(:,1))
    if data3(i-1,2)~=data3(i,2)
        Cname=[Cname; data3(i,2);];
        EaCoDaLength = [EaCoDaLength; count;];
              
        count =1;        
    else count = count +1;
    end
end
EaCoDaLength = [EaCoDaLength; count;];
ComName_Size=[Cname EaCoDaLength];

erase_list =[];

for i = 1 : length(ComName_Size(:,2))
    if ComName_Size(i,2) ~= 1135
       erase_list =[erase_list; ComName_Size(i,1)];
    end
end
delrow=[];
delcol=[];
for i= 1: length(erase_list)
[row, col]=find (data3== erase_list(i));
delrow=[delrow;row;];
end
data3(delrow,:)=[];


time = (data3(1:1135,1)); 
rawdata_All= zeros(length(time),length(Cname));



for i =1 : length(data3(:,2))
   if mod(i,1135)~= 0
    rownum = mod(i,1135);
    colnum = floor(i/1135)+1;
    
rawdata_All( rownum,colnum )= data3(i,3);

   else
        rownum = 1135;
        colnum = floor(i/1135);
        rawdata_All(rownum,colnum) = data3(i,3);
        
   end    
end
rawdata_All(:,(sum(rawdata_All)==0))=[];

