
#include <idc.idc>



static JpgTableTypeA(start, end) 
{
	auto ea, ref, len;
	auto str;

	ea = start;
	while( ea != BADADDR && ea < end )
	{
		ref = Dword(ea);
		len = Dword(ea +4);
		if( ref != 0 && len != 0 )
		{
			Message("%x %x %x\n", ea, ref, len);
			MakeData(ref, FF_BYTE, 1, 0 );
			MakeArray(ref, len);
			str = sprintf("jpg_%x",ref);
			//Message(str);
			MakeNameEx(ref, str, 0);
			OpOff(ea, 0, 0);	
		}
		
		ea = ea + 8;
	}
}


static main() 
{
    Message("Jpg Fix: Start\n");
	
	//d7000
	JpgTableTypeA(0x055db4, 0x055ebc );
	JpgTableTypeA(0x767a68, 0x767ba0 );

	Message("Jpg Fix: Done\n");
}


