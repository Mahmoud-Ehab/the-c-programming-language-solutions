/*
	Write a function invert(x,p,n) that returns x with the n bits that 
	begin at position p inverted.
*/


unsigned invert(unsigned x, int p, int n) {
	return (x >> (p-n+1)) ^ ~(~0 << n);
}
