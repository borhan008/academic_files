
function b = dec2binR(d, n)
size_d = size(d);
b = zeros(size_d(1), size_d(2));

for i = 1 : size_d(1)
    for j = 1 : size_d(2)
        abs_d = abs(d(i, j));

        abs_f = floor(abs_d);
        d_ = abs_d - abs_f;

        b1 = dec2bin(abs_f);

        b2 = zeros(1, n);

        for k = 1 : n
            d_ = d_ * 2;
            b2_ = num2str(floor(d_));
            b2(k) = b2_;
            d_ = d_ - floor(d_);
        end

        if d > 0
            b_ = [b1, '.', b2];
        else
            b_ = ['-', b1, '.', b2];
        end
        
        b(i, j) = str2num(b_);
    end
end
end
