
   #include <windows.h>

   void SetNumLock( BOOL bState )
   {
      BYTE keyState[256];

      GetKeyboardState((LPBYTE)&keyState);
      if( (bState && !(keyState[VK_NUMLOCK] & 1)) ||
          (!bState && (keyState[VK_NUMLOCK] & 1)) )
      {
      // Simulate a key press
         keybd_event( VK_NUMLOCK,
                      0x45,
                      KEYEVENTF_EXTENDEDKEY | 0,
                      0 );

      // Simulate a key release
         keybd_event( VK_NUMLOCK,
                      0x45,
                      KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP,
                      0);
      }
   }

   void main()
   {
      //SetNumLock( TRUE );

	  Sleep(5000);
keybd_event(16,0,0,0);//����Shift��
keybd_event('A',0,0,0);//����a��


keybd_event('A',0,KEYEVENTF_KEYUP,0);//�ɿ�a��
keybd_event(16,0,KEYEVENTF_KEYUP,0);//�ɿ�Shift��
//������ϼ�---->����Shift��ͬʱ����a���γ�A

   }

