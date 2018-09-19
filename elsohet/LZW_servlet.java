import java.text.StringBuffer;
import javax.servlet.*;

public class LZW_servlet implements Servlet
{
	ServletConfig config = null;
	
	public void init(ServletConfig config)
	{
		this.config = config;
	}
	
	public void service(ServletRequest request, ServletResponse response)
	{
		response.setContentType("text/html");
		
		/* TODO: here goes the LZW code */
		PrintWriter writer = result.getWriter();
		writer.print(LZWBinTreeHandler.treeToHTML(LZWBinTreeHandler.buildTree("")));
	}
	
	public void destroy()
	{
	}
	
	public ServletConfig getServletConfig()
	{
		return config;
	}
	
	public String getServletInfo()
	{
		return "Servlet for creating LZW binary trees";
	}
	
	/* No need to expose this class, output will be HTML anyways */
	private static class LZWBinTreeHandler
	{
		public LZWBinTree buildTree(String source)
		{
			
		}
		
		public String treeToHTML(LZWBinTree tree)
		{
			StringBuffer result = new StringBuffer();
			
			// TODO: use HTML5 canvas
		}
	}
	
	/* No need to expose this class, output will be HTML anyways */
	private static class LZWBinTree
	{
		private LZWBinTree	left	= null,
							right	= null;
		private	boolean		isRoot	= false;
							
		public LZWBinTree(boolean isRoot)
		{
			this.isRoot = isRoot;
		}
		
		public LZWBinTree getLeft()
		{
			return left;
		}
		
		public LZWBinTree getRight()
		{
			return right;
		}
		
		public void setLeft(LZWBinTree newLeft)
		{
			this.left = newLeft;
		}
		
		public void setRight(LZWBinTree newRight)
		{
			this.right = newRight;
		}
	}
}