
    print(f"Max Value : {X.max() : .4f}")
    print(f"Min Value : {X.min() : .4f}")
    print(f"Differece : {X.max() - X.min() : .4f}")
    print(f"Bins : {bins}")
    binned_dist, bin_edges = np.histogram(X, bins)
    probs = binned_dist / np.sum(binned_dist)
    
