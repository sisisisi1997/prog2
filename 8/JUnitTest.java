import org.junit.Test;
import static org.junit.Assert.assertEquals;

import java.lang.Math;

public class JUnitTest
{
	@Test
	public void testAverageForQQ()
	{
		LZWBinfa tree = new LZWBinfa("qq");
		assertEquals
		(
			Math.round(tree.getAverageDepth() * 10000.0) / 10000.0, // 4 tizedesjegyre kerekítve
			
		);
	}
	
	@Test
	public void testDeviationForQQ()
	{
		
	}
}