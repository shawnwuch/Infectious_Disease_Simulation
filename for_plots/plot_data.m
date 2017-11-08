% This script plots the outcome of disease simulation using the data
% stored in data.txt
clc; clear; close all;
people_num=200;
set(0,'defaultfigurecolor',[1 1 1]);
raw_data = importdata('../data.txt');
data = raw_data.data;
x = data(:,1); % disease transfer probability
y = data(:,2); % Inoculation fraction
z = data(:,3); % Avg disease run
j = data(:,4); % Avg stable ppl after disrease ends
k = data(:,5); % Avg number of people that have been sick in a disease run
xx = reshape(x, 21, 20);
yy = reshape(y, 21, 20);
zz = reshape(z, 21, 20);
jj = reshape(j, 21, 20);
kk = reshape(k, 21, 20);

figure();
surface( xx, yy, zz );
xlabel('Disease Transfer Probability');
ylabel('Fraction of Inoculated People');
zlabel('Average Disease Run (steps)');
set(gca, 'fontsize', 14);
grid on; 
box on;

figure();
surface( xx, yy, kk );
xlabel('Disease Transfer Probability');
ylabel('Fraction of Inoculated People');
zlabel('Average Number of People Infected by the Disease');
set(gca, 'fontsize', 14);
grid on; 
box on;

figure();
ax = scatter( xx(kk <= people_num * 0.05), yy(kk <= people_num * 0.05), 'filled' );
set(ax, 'linewidth', 1.2, 'markeredgecolor', 'k');
xlabel('Disease Transfer Probability');
ylabel('Fraction of Inoculated People');
title('Cases where >= 95% of People Never Get Sick')
set(gca, 'fontsize', 14);
grid on; 
box on;
% zlabel('');