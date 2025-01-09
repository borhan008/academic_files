NodeSize=size(G,1);
CountHierarchyPath=0;
Degree=sum(G);

S=sparse(G);

for i=1:NodeSize %shortest path�� ó������ ��� i
    [dist, path, ~] = graphshortestpath(S, i);
    for j=i+1:NodeSize %shortest path�� ������ ���� ��� j
        if dist(j)==1 % shortest path�� direct connect�� ��� ������ Hierarchy path�̴�.
            CountHierarchyPath=CountHierarchyPath+1;
            continue
        end
        
        
        ChangeBool=0;
        for k=1:dist(j) % k�� path�� ���󰡴� ��
            Measure1=Degree(path{1,j}(1,k+1))-Degree(path{1,j}(1,k));
            if Measure1<0; %path�� ���� �� k��° degree ���̰� 0���� ������(down path)
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