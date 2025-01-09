TEST_FULL_SPARAE=1;
nodes_attribute=1;
if nodes_attribute==1
    if TEST_FULL_SPARAE==1
        Node_CC=zeros(185,1);
    elseif TEST_FULL_SPARAE==2
        Nodes_CC=sparse(185,1);
    end
    
    for i=1:185
        triangle_num=0;
        Neighbor=find(Adj_dur13(i,:)>0);
        node_degree=nnz(Neighbor);
        if node_degree==0||node_degree==1
            Node_CC(i)=0;              
        else
            triple_num=node_degree*(node_degree-1)/2;
            for j=1:(node_degree-1)
                for k=(j+1):node_degree
                    if Adj_dur13(Neighbor(j),Neighbor(k))>0
                        triangle_num=triangle_num+1;
                    end
                end
            end
            Node_CC(i)=triangle_num/triple_num;
        end        
    end   
    cc=sum(Node_CC)/185;
end


[pdf4,X4]= hist(Mean,100);
pdf4 = pdf4/sum(pdf4);
plot(X4,pdf4)

[pdf5,X5]= hist(Crosstest,100);
pdf5 = pdf5/sum(pdf5);
plot(X5,pdf5,'-r')

[pdf6,X6]= hist(Cross_glo_aft,100);
pdf6 = pdf6/sum(pdf6);
plot(X6,pdf6,'-m')

Summation of raw:
All=sum(matrix,2);



