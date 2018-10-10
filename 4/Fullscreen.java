import java.awt.Frame;

public class Fullscreen extends java.awt.Frame
{
	java.awt.GraphicsDevice gd;
	
	public static void main(String[] args)
	{
		new Fullscreen();
	}
	
	public Fullscreen()
	{
		java.awt.GraphicsEnvironment ge = java.awt.GraphicsEnvironment.getLocalGraphicsEnvironment();
		gd = ge.getDefaultScreenDevice();
		
		setUndecorated(true);
		setResizable(false);
		if(gd.isFullScreenSupported())
		{
			gd.setFullScreenWindow(this);
		}
		else
		{
			setSize(800, 600);
		}
		
		addKeyListener(new java.awt.event.KeyAdapter()
		{
		public void keyPressed(java.awt.event.KeyEvent event)
			{
				System.exit(0);
			}
		});
	}
}