public class Rational extends Number implements Creator {
	private long numerator = 0;
	private long denominator = 1;
	public Rational() {
		this(0,1);
	}
	public Rational(long numerator, long denominator) {
		long theGcd = gcd(numerator, denominator);
		this.numerator = ((denominator > 0) ? 1 : -1) * numerator / theGcd;
		this.denominator = Math.abs(denominator) / theGcd;
	}
	private static long gcd (long n, long d) {
		if(n<0) n *= -1;
		if(d<0) d *= -1;
		return (d !=0 ? gcd(d, n%d) : n);
	}
	public long getNumerator() {return numerator;}
	public long getDenominator() {return denominator;}
	public Rational add(Rational secondRational) {
		long n3, d3;
		n3 = numerator * secondRational.getDenominator() + secondRational.getNumerator() * denominator;
		d3 = denominator * secondRational.getDenominator();
		long theGcd = gcd(n3, d3);
		n3 /= theGcd;
		d3 /= theGcd;
		return new Rational(n3, d3);
	}
	public Rational subtract(Rational secondRational) {
		long n3, d3;
		n3 = numerator * secondRational.getDenominator() - secondRational.getNumerator() * denominator;
		d3 = denominator * secondRational.getDenominator();
		long theGcd = gcd(n3, d3);
		n3 /= theGcd;
		d3 /= theGcd;
		return new Rational(n3, d3);
	}
	public Rational multiply(Rational secondRational) {
		long n3, d3;
		n3 = numerator * secondRational.getNumerator();
		d3 = denominator * secondRational.getDenominator();
		long theGcd = gcd(n3, d3);
		n3 /= theGcd;
		d3 /= theGcd;
		return new Rational(n3, d3);
	}
		
	public Rational divide(Rational secondRational) {
		long n3, d3;
		n3 = numerator * secondRational.getDenominator();
		d3 = denominator * secondRational.getNumerator();
		long theGcd = gcd(n3, d3);
		n3 /= theGcd;
		d3 /= theGcd;
		return new Rational(n3, d3);
	}
	@Override
	public String toString() {
		if(denominator == 1)
			return Long.toString(numerator);
		else
			return Long.toString(numerator) + "/" + Long.toString(denominator); 
			
	}
	@Override
	public boolean equals(Object other ) {
		Rational otherR = (Rational)other;
		if(numerator == otherR.getNumerator() && denominator == otherR.getDenominator())
			return true;
		else
			return false;
	}
	@Override
	public int intValue() {return (int)numerator;}
	@Override
	public float floatValue() {return (float)numerator / (float)denominator;}
	@Override
	public double doubleValue() {return (double)numerator / (double)denominator;}
	@Override
	public long longValue(){return numerator;}
	@Override
	public void CreatorOfThisClass() {
	System.out.println("Creator of this class is 2021313504");
	}
}