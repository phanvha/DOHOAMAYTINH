void ClipEdge(POINT *pIn, int N, POINT *pOut, int &Cnt, int Edge, RECT rWin)
{
	int FlagPrevPt = FALSE;
	Cnt = 0;
	POINT pPrev;
	pPrev = pIn[0];
	if(Inside(pPrev, Edge, rWin)) // Save point
	{
		pOut[Cnt] = pPrev;Cnt++;FlagPrevPt = TRUE;
	}
	for(int i=1; i<N; i++)
	{
		if(FlagPrevPt) // Diem bat dau nam trong
		{
			if(Inside(pIn[i], Edge, rWin)) // Save point P
			{
				pOut[Cnt] = pIn[i];Cnt++;
			}else // Save I
			{
				FlagPrevPt = FALSE;
				pOut[Cnt] = Intersect(pPrev, pIn[i], Edge, rWin);
				Cnt++;
			}
		}else // Diem bat dau canh nam ngoai
		{
			if(Inside(pIn[i], Edge, rWin)) // Save point I, ?
			{
				FlagPrevPt = TRUE;pOut[Cnt] = Intersect(pPrev, pIn[i], Edge, rWin);Cnt++;
				pOut[Cnt] = pIn[i];Cnt++;
			}
		}pPrev = pIn[i];
	}// Neu Diem cuoi va dau giao voi bien cua cua so Save point I
	if(!(Inside(pIn[N], Edge, rWin) == Inside(pPrev, Edge, rWin)))
	{
		pOut[Cnt] = Intersect(pPrev, pIn[N], Edge, rWin);
		Cnt++;
	}pOut[Cnt] = pOut[0];
}// ClipEdge
