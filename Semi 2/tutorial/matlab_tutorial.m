clear all
clc
close all

y=csvread('dataset_2.csv');

num_of_bins=100;
bin_size=(max(y)-min(y))/num_of_bins;
bin_count=zeros(1,num_of_bins);
bin_center=zeros(1,num_of_bins);

%this for loop is to put each y into their bins
for i=1:1:length(y)
    if y(i)==min(y)
        bin_num=1;
    else
        bin_num=abs(ceil((y(i)-min(y))/bin_size));
    end
    bin_count(bin_num)=bin_count(bin_num)+1;
end

%this loop is for calculating midpoints of bins
for i=1:1:num_of_bins
    bin_center(i)=min(y)+(2*i-1)/2*bin_size;
end

%using vectorization to calculate the mean and variance
calc_mean=sum(bin_center.*bin_count/length(y))
calc_var=sum(bin_count.*(bin_center-calc_mean).^2/length(y))
calc_std=sqrt(calc_var)
actual_mean=mean(y)
actual_var=var(y)
actual_std=std(y)
%plotting the graphs
normalized=bin_count/(sum(bin_count.*bin_size));
hold on
bar(bin_center,normalized,'hist');
x=min(y):0.001:max(y);
p=1/sqrt(2*pi*calc_var)*exp(-(x-calc_mean).^2/2/calc_var);
plot(x,p,'r');
title('Histogram');
xlabel('voltage');ylabel('Frequency');
hold off
        








