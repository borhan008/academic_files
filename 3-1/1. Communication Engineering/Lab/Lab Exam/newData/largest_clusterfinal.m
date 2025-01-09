 A=Adj1;
    A(1:end,i)=0;
    A(i,1:end)=0;
    N = size(A,1);
% Remove diagonals
A(1:N+1:end) = 0;
% Have we visited a particular node yet?
isDiscovered = zeros(N,1);
% Empty members cell
members = {};
% check every node
for n=1:N
    if ~isDiscovered(n)
        % started a new group so add it to members
        members{end+1} = n;
        % account for discovering n
        isDiscovered(n) = 1;
        % set the ptr to 1
        ptr = 1;
        while (ptr <= length(members{end}))
            % find neighbors
            nbrs = find(A(:,members{end}(ptr)));
            % here are the neighbors that are undiscovered
            newNbrs = nbrs(isDiscovered(nbrs)==0);
            % we can now mark them as discovered
            isDiscovered(newNbrs) = 1;
            % add them to member list
            members{end}(end+1:end+length(newNbrs)) = newNbrs;
            % increment ptr so we check the next member of this cluster
            ptr = ptr+1;
        end
    end
end
% number of clusters
nClusters = length(members);
for n=1:nClusters
    % compute sizes of clusters
    sizes(n) = length(members{n});
end
% find the biggest one
idxLargestCluster = find(sizes==max(sizes));
S=max(sizes)
F=sum(S)/30;