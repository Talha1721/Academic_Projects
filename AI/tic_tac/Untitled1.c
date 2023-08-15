footBall=imread('football.jpg');
%Convert to grayscalefootBall=rgb2gray(footBall);
imshow(footBall)%Determine good padding for Fourier transformPQ = paddedsize(size(footBall));
%Create a Gaussian Lowpass filter 5% the width of the Fourier transformD0 = 0.05*PQ(1);
H = lpfilter('gaussian', PQ(1), PQ(2), D0);
% Calculate the discrete Fourier transform of the imageF=fft2(double(footBall),size(H,1),size(H,2));
% Apply the highpass filter to the Fourier spectrum of the imageLPFS_football = H.*F;
% convert the result to the spacial domain.LPF_football=real(ifft2(LPFS_football));
% Crop the image to undo paddingLPF_football=LPF_football(1:size(footBall,1), 1:size(footBall,2));
%Display the blurred imagefigure, imshow(LPF_football, [])% Display the Fourier Spectrum % Move the origin of the transform to the center of the frequency rectangle.Fc=fftshift(F);
Fcf=fftshift(LPFS_football);