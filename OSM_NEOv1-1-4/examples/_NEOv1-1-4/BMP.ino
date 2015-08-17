// BPM.ino


float BPM_Bars(float BPM, byte bars)

{
	float BPM_Result;
	//BPM_Result = ((((480/BPM) * 1000) / 16.40) * 2) ;
	BPM_Result = ((((480/BPM) * 1000) / 16.40) * bars) ;
	return BPM_Result;
}




float BPM_Beats(float BPM)

{
	float BPM_Result;
	BPM_Result = (6000/BPM);
	return BPM_Result;
}

