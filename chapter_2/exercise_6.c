/*
	Write a function setbits(x,p,n,y) that returns x with the n bits
	that begin at position p set to the rightmost n bits of y, leaving
	the other bits unchanged.
*/


unsigned setbits(unsigned x, int p, int n, unsigned y) {
	// adjust y to has n 0-bits at the rightmost
	unsigned yb = y & (~0 << n);
	
	// get the rightmost n bits of x at position p
	unsigned xb = (x >> (p-n+1)) & ~(~0 << n);

	return yb | xb;
}
