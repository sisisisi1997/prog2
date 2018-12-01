import android.content.Context;
import android.os.Bundle;

import android.content.pm.PackageManager;
import android.location.Location;
import android.location.LocationListener;
import android.location.LocationManager;
import android.support.v4.content.ContextCompat;

import static android.content.Context.LOCATION_SERVICE;

public class GpsTracker implements LocationListener
{
	Context context;
	
	public GpsTracker(Context context)
	{
		super();
		this.context = context;
	}
	
	public Location getLocation()
	{
		if(ContextCompat.checkSelfPermission(context, android.Manifest.permission.ACCESS_FINE_LOCATION) != PackageManager.PERMISSION_GRANTED)
		{
			return null;
		}
		try
		{
			LocationManager lm = (LocationManager)context.getSystemService(LOCATION_SERVICE);
			if(lm.isProviderEnabled(LocationManager.GPS_PROVIDER))
			{
				lm.requestLocationUpdates(LocationManager.GPS_PROVIDER, 3000, 0, this);
				return lm.getLastKnownLocation(LocationManager.GPS_PROVIDER);
			}
		}
		catch (Exception e)
		{
			e.printStackTrace();
		}
		return null;
	}
	
	@Override
	public void onLocationChanged(Location location)
	{
	}
	
	@Override
	public void onStatusChanged(String provider, int status, Bundle extras)
	{
	}
	
	@Override
	public void onProviderEnabled(String provider)
	{
	}
	
	@Override
	public void onProviderDisabled(String provider)
	{
	}
}
