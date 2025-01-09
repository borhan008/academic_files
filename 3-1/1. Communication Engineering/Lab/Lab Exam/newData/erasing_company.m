A1=sortrows(A2,4);
Cname=A1(1,4);
EaCoDaLength = [];
count =1;
for i =2: length(A1(:,2))
if A1(i-1,4)~=A1(i,4)
Cname=[Cname; A1(i,4);];
EaCoDaLength = [EaCoDaLength; count;];
count =1;
else count = count +1;
end
end
EaCoDaLength = [EaCoDaLength; count;];
ComName_Size=[Cname EaCoDaLength];
ComName_Size=[Cname EaCoDaLength]
erase_list =[];
for i = 1 : length(ComName_Size(:,2))
if ComName_Size(i,2) <= 200
erase_list =[erase_list; ComName_Size(i,1)];
end
end
delrow=[];
delcol=[];
for i= 1: length(erase_list)
[row, col]=find (A1== erase_list(i));
delrow=[delrow;row;];
end
A1(delrow,:)=[];
