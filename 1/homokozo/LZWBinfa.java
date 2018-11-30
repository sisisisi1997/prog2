package homokozo;

import java.io.*;
import java.lang.Math;

public class LZWBinfa
{
	static class Node
	{
		private char	mNodeVal;
		private Node	mLeftChild = null,
						mRightChild = null;
		
		public Node(char val)
		{
			this.mNodeVal = val;
		}
		
		public Node getLeftChild()
		{
			return this.mLeftChild;
		}
		
		public void setLeftChild(Node value)
		{
			this.mLeftChild = value;
		}
		
		public Node getRightChild()
		{
			return this.mRightChild;
		}
		
		public void setRightChild(Node value)
		{
			this.mRightChild = value;
		}
		
		public char getNodeValue()
		{
			return this.mNodeVal;
		}
	}
	
	private Node mTreeRoot;
	
	public LZWBinfa(String input)
	{
		this.mTreeRoot = new Node('/');
		
		Node position = this.getRootNode();
		
		char[] inputC = input.toCharArray();
		for(int charIndex = 0; charIndex < inputC.length; ++ charIndex) // 16 bites de hogy teljesen egyezzen a viselkedés a C verzióval, csak nyolcat nézünk majd
		{
			for(int i = 0; i < 8; ++ i)
			{
				int lastBit = inputC[charIndex] % 2;
				if(lastBit == 0)
				{
					if(position.getLeftChild() == null)
					{
						position.setLeftChild(new Node('0'));
						position = this.getRootNode();
					}
					else
					{
						position = position.getLeftChild();
					}
				}
				else
				{
					if(position.getRightChild() == null)
					{
						position.setRightChild(new Node('1'));
						position = this.getRootNode();
					}
					else
					{
						position = position.getRightChild();
					}
				}
				inputC[charIndex] >>= 1;
			}
		}
		
		this.calculateStatistics();
	}
	
	private int		nodeCount = 0;
	private double	avg = 0,
					deviation = 0;
	
	private void calculateStatistics()
	{
		prepareAvg(this.getRootNode(), 0);
		avg /= nodeCount;
		prepareDeviation(this.getRootNode(), 0);
		deviation = Math.sqrt(deviation / ((nodeCount > 1) ? (nodeCount - 1) : (1)));
	}
	
	private void prepareAvg(Node pos, int depth)
	{
		if(pos != null)
		{
			prepareAvg(pos.getLeftChild(), depth + 1);
			prepareAvg(pos.getRightChild(), depth + 1);
			
			if(pos.getLeftChild() == null && pos.getRightChild() == null)
			{
				++ nodeCount;
				avg += depth;
			}
		}
	}
	
	private void prepareDeviation(Node pos, int depth)
	{
		if(pos != null)
		{
			prepareDeviation(pos.getLeftChild(), depth + 1);
			prepareDeviation(pos.getRightChild(), depth + 1);
			
			if(pos.getLeftChild() == null && pos.getRightChild() == null)
			{
				deviation += ((depth - avg) * (depth - avg));
			}
		}
	}
	
	public double getAverageDepth()
	{
		return avg;
	}
	
	public double getDepthDeviation()
	{
		return deviation;
	}
	
	public Node getRootNode()
	{
		return this.mTreeRoot;
	}
	
	public String printTree()
	{
		return printTreeInternal(this.getRootNode(), 0);
	}
	
	private String printTreeInternal(Node pos, int depth)
	{
		String sofar = "";
		if(pos.getLeftChild() != null)
		{
			sofar += printTreeInternal(pos.getLeftChild(), depth + 1);
		}
		
		char nodeVal = pos.getNodeValue();
		for(int i = 0; i < depth - 1; ++ i)
		{
			sofar += "  ";
			//System.out.print("  ");
		}
		if(depth != 0)
		{
			if(nodeVal == '0')
			{
				sofar += "/-";
				//System.out.print("/-");
			}
			else if(nodeVal == '1')
			{
				sofar += "\\-";
				//System.out.print("\\-");
			}
		}
		sofar += String.valueOf(pos.getNodeValue()) + "\n";
		//System.out.println(pos.getNodeValue());
		
		if(pos.getRightChild() != null)
		{
			sofar += printTreeInternal(pos.getRightChild(), depth + 1);
		}
		
		return sofar;
	}
	
	/*public static void main(String[] args)
	{
		if(args.length == 0)
		{
			System.out.println("Nincs megadva bemenet. Használat:\n> java LZWBinfa bemenet\nahol bemenet egy space-t nem tartalmazó ascii karakterekből álló szöveg");
			return;
		}
		
		LZWBinfa tree = new LZWBinfa(args[0]);
		tree.printTree();
		System.out.println("Átlag mélység: " + Double.toString(tree.getAverageDepth()));
		System.out.println("Szórás: " + Double.toString(tree.getDepthDeviation()));
	}*/
}