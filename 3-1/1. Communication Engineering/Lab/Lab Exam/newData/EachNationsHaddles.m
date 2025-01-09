%% input starting date //  endday ; 

SDay = '1/1/1998';
EDay = '12/20/2012';

SDay = datenum(SDay); 
EDay = datenum(EDay); 

TIME = [SDay:1:EDay]';
AllDATA = TIME; 


files = dir('*csv');
f_len = length(files); 

for i=1:f_len

eval(['[data1 data2 data3]= xlsread(' mat2str(files(i).name) ')';]); 

data = data1(:,4); %%%%%%%%%%% I am not sure 
data2 = data2(:,1);  
data2= datenum(data2); 
num =0; 
for j = data2' 
    num = num+1; 
    AllDATA(j-SDay+1,i+1)=data(num);
end

end



%% thecell( all(cellfun(@isempty,thecell),2), : ) = []