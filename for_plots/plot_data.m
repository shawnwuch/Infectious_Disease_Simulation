% This script plots the outcome of disease simulation using the data
% stored in data.txt
clc; clear; close all;

set(0,'defaultfigurecolor',[1 1 1]);
figure();
raw_data = importdata('../data.txt');
data = raw_data.data;
x = data(:,1); % disease transfer probability
y = data(:,2); % Inoculation fraction
z = data(:,3); % Avg disease run
k = data(:,4); % Avg stable ppl after disrease ends
xx = reshape(x, 21, 20);
yy = reshape(y, 21, 20);
zz = reshape(z, 21, 20);
kk = reshape(k, 21, 20);


surface( xx, yy, zz );
xlabel('Disease Transfer Probability');
ylabel('Inoculation Fraction');
zlabel('Average Disease Run (steps)');
set(gca, 'fontsize', 14);
grid on; 
box on;
