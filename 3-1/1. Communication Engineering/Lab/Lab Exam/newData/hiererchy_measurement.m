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