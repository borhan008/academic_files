

load Final_RAWALLDATA.txt
RAWDATA=Final_RAWALLDATA(1:250,:);
[rownum colnum]= size(RAWDATA);
for i=1:rownum-1
for j=1:colnum
retun_test1(i,j)=log(RAWDATA(i+1,j))-log(RAWDATA(i,j));
end
end

Retun=retun_test1;
q=0;
for t=1:15

for l=1:500
Retun= Retun(:,randperm(size(Retun,2)));

       retun_all=Retun(:,1:10*t);
       Crossusnew0=corrcoef(retun_all);
    
       d=Crossusnew0;
       n = size (d,1); %Number of vertices
    for i=1:n
        for j=1:n
            d(i,j)=sqrt(2*(1-(d(i,j)))); %make distance matrix
        end
    end

   
EdgeWeights = 0; 
EdgeWeightsCounter = 0;
for i = 1:n
for j = (i+1):n
if (( d(i,j))~=inf)
EdgeWeightsCounter = EdgeWeightsCounter + 1;
EdgeWeights(EdgeWeightsCounter,1) =  d(i,j);
EdgeWeights(EdgeWeightsCounter,2) = i;
EdgeWeights(EdgeWeightsCounter,3) = j;
end
 end
end
SortedEdgeWeights = 0;
SortedEdgeWeights = sortrows(EdgeWeights);

m = size(SortedEdgeWeights,1); 


ParentPointer = 0;
ParentPointer(1:n) = 1:n;

TreeRank = 0;
TreeRank(1:n) = 0;

MSTreeEdges = 0;
MSTreeEdgesCounter = 0; i = 1;
while ((MSTreeEdgesCounter < (n-1)) && (i<=m))

root1=0; root2=0; temproot=0;
temproot = SortedEdgeWeights(i,2);
root1 = FIND_PathCompression(temproot);
temproot = SortedEdgeWeights(i,3);
root2 = FIND_PathCompression(temproot);
if (root1 ~= root2)
MSTreeEdgesCounter = MSTreeEdgesCounter + 1;
MSTreeEdges(MSTreeEdgesCounter,1:3) = SortedEdgeWeights(i,:);
if (TreeRank(root1)>TreeRank(root2))
ParentPointer(root2)=root1;
else
if (TreeRank(root1)==TreeRank(root2))
TreeRank(root2)=TreeRank(root2) + 1;
end
ParentPointer(root1)=root2;
end
end
i = i + 1;
end
cost = sum (MSTreeEdges(:,1));
MSTreeEdgesCounter = 0;
M5= 0;
M5(1:n,1:n)=0;
while (MSTreeEdgesCounter < (n-1))
MSTreeEdgesCounter = MSTreeEdgesCounter + 1;
M5(MSTreeEdges(MSTreeEdgesCounter,2),MSTreeEdges(MSTreeEdgesCounter,3))=1; M5(MSTreeEdges(MSTreeEdgesCounter,3),MSTreeEdges(MSTreeEdgesCounter,2))=1;
end

G=M5;

NodeSize=size(G,1);
CountHierarchyPath=0;
Degree=sum(G);

S=sparse(G);

for i=1:NodeSize %shortest path의 처음시작 노드 i
    [dist, path, ~] = graphshortestpath(S, i);
    for j=i+1:NodeSize %shortest path의 마지막 종점 노드 j
        if dist(j)==1 % shortest path가 direct connect인 경우 무조껀 Hierarchy path이다.
            CountHierarchyPath=CountHierarchyPath+1;
            continue
        end
        
        
        ChangeBool=0;
        for k=1:dist(j) % k는 path를 따라가는 길
            Measure1=Degree(path{1,j}(1,k+1))-Degree(path{1,j}(1,k));
            if Measure1<0; %path를 따라갈 때 k번째 degree 차이가 0보다 작을때(down path)
                ChangeBool=1;
            end
            if ChangeBool==1 && Measure1>0
                break
            end
            if k==dist(j)
                CountHierarchyPath=CountHierarchyPath+1;
            end
        end
        
    end
    
end


F=2*CountHierarchyPath/(NodeSize*(NodeSize-1));

Hie(l)=F;

end
q=q+1
Kospihie2003(t)=mean(Hie);
clear M5
clear d
end