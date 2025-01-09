files = dir ('*.dat');
f_len = length(files);

for k= 1: f_len
    eval (['load ' files(k).name]);
    name = files(k).name(1:end-4);
    eval (['a=' name]);
    
    
    n = size (d,1); %Number of vertices
    for i=1:n
        for j=1:n
            d(i,j)=sqrt(2*(1-(d(i,j)))); %make distance matrix
        end
    end
        
    
    pdist = 0;         %Edges and corresponding weights
    EdgeWeightsCounter = 0;
    for i = 1:n-1
        for j = (i+1):n
            EdgeWeightsCounter = EdgeWeightsCounter + 1;
            pdist(1,EdgeWeightsCounter) = d(i,j);
        end
    end
    Z1 = linkage(pdist,'average');
    Z2 = linkage(pdist,'centroid');
    Z3 = linkage(pdist,'complete');
    Z4 = linkage(pdist,'median');
    Z5 = linkage(pdist,'single');
    
    dendrogram(Z1,0)  % If you want to see dendrogram of other making linkage methods
    
    %Plz change Z1 to other.
    
    % And dendrogram(Z1,0 <--this num. is what is the number of drawing elements
    % (zero is draw all elements)
    
    saveas(gcf,sprintf('Dendrogram_average_All_%s',name));
    
end
cophentic correlation coefficient:
    Cop02= cophenet(Z1,pdist)
    
    D = pdist(d,'euclidean');
Z = linkage(D,'average');

dlmwrite('Copentic_after.txt',Copentic_after,'delimiter','\t');
