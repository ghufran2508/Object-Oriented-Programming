#include <iostream>
#include"MobilePhone.h"
#include"ApplePhone.h"
#include"AndroidPhone.h"
#include"WindowPhone.h"

int main()
{
	ApplePhone ap;
	ap.setMfgID(120283);
	ap.setMfgDate("30/11/2020");
	ap.setMfgName("FoxConn");
	ap.setiOSVersion("14.2");
	ap.turnOn();
	ap.makeVoiceCall(9202319);
	ap.launchPaper();
	ap.turnOff();

	AndroidPhone anp;
	anp.setiOSVersion("123");
	anp.setKernelVersion("asd");
	//anp.turnOn();
	//anp.makeVoiceCall(0300);
	anp.launchFlynx();
	/*anp.turnOff();*/

	WindowsPhone wp;
	/*wp.turnOn();*/
	wp.launchXboxGame();
	/*wp.sendSMS("Text messaging not allowed in lab!", 02323);
	wp.turnOff();*/

	return 0;
}
