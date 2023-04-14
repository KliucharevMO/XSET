open_home_page() {
	
	lr_start_transaction("open_home_page");
	
		web_reg_find("Text/IC=Welcome to the Web Tours site",
		LAST);

		web_add_auto_header("Sec-Fetch-Site", 
			"none");
	
		web_add_auto_header("Sec-Fetch-Dest", 
			"document");
	
		web_add_auto_header("Sec-Fetch-Mode", 
			"navigate");
	
		web_add_auto_header("Sec-Fetch-User", 
			"?1");
	
		web_add_auto_header("Upgrade-Insecure-Requests", 
			"1");
	
		web_add_auto_header("sec-ch-ua", 
			"\"Chromium\";v=\"112\", \"Google Chrome\";v=\"112\", \"Not:A-Brand\";v=\"99\"");
	
		web_add_auto_header("sec-ch-ua-mobile", 
			"?0");
	
		web_add_auto_header("sec-ch-ua-platform", 
			"\"{seatingPreference}s\"");
	
		/*Correlation comment - Do not change!  Original value='136172.171891454HAAtDfzpAQVzzzzHtcAczpVDzff' Name ='userSession' Type ='ResponseBased'*/
		web_reg_save_param_attrib(
			"ParamName=userSession",
			"TagName=input",
			"Extract=value",
			"Name=userSession",
			"Type=hidden",
			SEARCH_FILTERS,
			"IgnoreRedirections=No",
			"RequestUrl=*/nav.pl*",
			LAST);
	
		web_url("WebTours", 
				"URL=http://localhost:1080/WebTours/", 
				"TargetFrame=", 
				"Resource=0", 
				"RecContentType=text/html", 
				"Referer=", 
				"Snapshot=t1.inf", 
				"Mode=HTML", 
				LAST);
		
	lr_end_transaction("open_home_page", LR_AUTO);
	
	return 0;
}

login() {
	
	lr_start_transaction("login");
	
		web_reg_find("Text/IC=User password was correct",
		LAST);
	
		web_reg_find("Text/IC=Welcome, <b>{userLogin}</b>, to the Web Tours reservation pages.",
		LAST);

		web_add_auto_header("Sec-Fetch-Dest", 
			"frame");
	
		web_revert_auto_header("Sec-Fetch-User");
	
		web_revert_auto_header("Upgrade-Insecure-Requests");
	
		web_add_header("Origin", 
			"http://localhost:1080");
	
		web_add_auto_header("Sec-Fetch-Site", 
			"same-origin");
	
		web_submit_data("login.pl",
		"Action=http://localhost:1080/cgi-bin/login.pl",
		"Method=POST",
		"TargetFrame=body",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/nav.pl?in=home",
		"Snapshot=t2.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=userSession", "Value={userSession}", ENDITEM,
		"Name=username", "Value={userLogin}", ENDITEM,
		"Name=password", "Value={userPassword}", ENDITEM,
		"Name=login.x", "Value=49", ENDITEM,
		"Name=login.y", "Value=8", ENDITEM,
		"Name=JSFormSubmit", "Value=off", ENDITEM,
		LAST);
	
	lr_end_transaction("login", LR_AUTO);
	
	return 0;
}

logout() {
	
	lr_start_transaction("logout");
	
		web_reg_find("Text/IC=Welcome to the Web Tours site",
		LAST);

		web_revert_auto_header("Sec-Fetch-User");
	
		web_url("SignOff Button", 
			"URL=http://localhost:1080/cgi-bin/welcome.pl?signOff=1", 
			"TargetFrame=body", 
			"Resource=0", 
			"RecContentType=text/html", 
			"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=itinerary", 
			"Snapshot=t8.inf", 
			"Mode=HTML", 
			LAST);
		
	lr_end_transaction("logout", LR_AUTO);
	
	return 0;
}

open_flight_selections_page() {
	
		lr_start_transaction("open_flight_selections");
	

		web_reg_find("Text/IC=Departure Date Applet",
		LAST);

		web_add_auto_header("Sec-Fetch-User", 
			"?1");
	
		web_add_auto_header("Upgrade-Insecure-Requests", 
			"1");
	
	
		web_url("Search Flights Button", 
			"URL=http://localhost:1080/cgi-bin/welcome.pl?page=search", 
			"TargetFrame=body", 
			"Resource=0", 
			"RecContentType=text/html", 
			"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
			"Snapshot=t3.inf", 
			"Mode=HTML", 
			LAST);
	
	lr_end_transaction("open_flight_selections", LR_AUTO);
	
	return 0;
}

selection_flight() {
	
	lr_start_transaction("selection_flight");
	
		web_reg_find("Text/IC=Flight Selections",
		LAST);
	
		web_reg_find("Text/IC=Flight departing from <B>{departureCity}</B> to <B>{arrivalCity}</B> on <B>{departureDate}</B>",
		LAST);


		web_add_auto_header("Origin", 
			"http://localhost:1080");
	
		/*Correlation comment - Do not change!  Original value='822;1975;12/25/2023' Name ='outboundFlight' Type ='ResponseBased'*/
		web_reg_save_param_attrib(
			"ParamName=outboundFlight",
			"TagName=input",
			"Extract=value",
			"Name=outboundFlight",
			"Type=radio",
			SEARCH_FILTERS,
			"IgnoreRedirections=No",
			LAST);
	
		web_submit_data("reservations.pl", 
				"Action=http://localhost:1080/cgi-bin/reservations.pl", 
				"Method=POST", 
				"TargetFrame=", 
				"RecContentType=text/html", 
				"Referer=http://localhost:1080/cgi-bin/reservations.pl?page=welcome", 
				"Snapshot=t4.inf", 
				"Mode=HTML", 
				ITEMDATA, 
				"Name=advanceDiscount", "Value=0", ENDITEM, 
				"Name=depart", "Value={departureCity}", ENDITEM, 
				"Name=departDate", "Value={departureDate}", ENDITEM, 
				"Name=arrive", "Value={arrivalCity}", ENDITEM, 
				"Name=returnDate", "Value={returnDate}", ENDITEM, 
				"Name=numPassengers", "Value=1", ENDITEM, 
				"Name=seatPref", "Value={seatingPreference}", ENDITEM, 
				"Name=seatType", "Value={typeSeat}", ENDITEM, 
				"Name=findFlights.x", "Value=52", ENDITEM, 
				"Name=findFlights.y", "Value=9", ENDITEM, 
				"Name=.cgifields", "Value=roundtrip", ENDITEM, 
				"Name=.cgifields", "Value=seatType", ENDITEM, 
				"Name=.cgifields", "Value=seatPref", ENDITEM, 
				LAST);

	lr_end_transaction("selection_flight", LR_AUTO);
	
	return 0;
}

reservation_flight() {
	
	lr_start_transaction("reservation_flight");
	
		web_reg_find("Text/IC=Flight Reservation",
		LAST);

	
		web_submit_data("reservations.pl_2",
		"Action=http://localhost:1080/cgi-bin/reservations.pl",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/reservations.pl",
		"Snapshot=t5.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=outboundFlight", "Value={outboundFlight}", ENDITEM,
		"Name=numPassengers", "Value=1", ENDITEM,
		"Name=advanceDiscount", "Value=0", ENDITEM,
		"Name=seatType", "Value={typeSeat}", ENDITEM,
		"Name=seatPref", "Value={seatingPreference}", ENDITEM,
		"Name=reserveFlights.x", "Value=57", ENDITEM,
		"Name=reserveFlights.y", "Value=9", ENDITEM,
		LAST);
	
	lr_end_transaction("reservation_flight", LR_AUTO);
	
	return 0;
}

payment() {
	
		lr_start_transaction("payment");
	
		web_reg_find("Text/IC=Reservation Made!",
		LAST);
	
		web_reg_find("Text/IC=<b>{userFirstName}{userLastName}'s Flight Invoice</b>",
		LAST);

		web_reg_find("TextPfx/IC=A {typeSeat} Class ticket",
		"TextSfx/IC= from {departureCity} to {arrivalCity}.",
		LAST);

		web_reg_find("TextPfx/IC/DIG={departureDate} :  ",
		"TextSfx/IC/DIG= : Flight ### leaves {departureCity}  for {arrivalCity}.",
		LAST);
	
		web_reg_find("Text/IC=Total Charged to Credit Card # {creditCardNumber}",
		LAST);
	
		web_revert_auto_header("Origin");
	
		web_revert_auto_header("Sec-Fetch-User");
	
		web_revert_auto_header("Upgrade-Insecure-Requests");
	
		web_add_header("Origin", 
			"http://localhost:1080");
	
		web_submit_data("reservations.pl_3",
		"Action=http://localhost:1080/cgi-bin/reservations.pl",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/reservations.pl",
		"Snapshot=t6.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=firstName", "Value={userFirstName}", ENDITEM,
		"Name=lastName", "Value={userLastName}", ENDITEM,
		"Name=address1", "Value={addressStreet}", ENDITEM,
		"Name=address2", "Value={addressCity}", ENDITEM,
		"Name=pass1", "Value={userFirstName} {userLastName}", ENDITEM,
		"Name=creditCard", "Value={creditCardNumber}", ENDITEM,
		"Name=expDate", "Value={creditCardExpDate}", ENDITEM,
		"Name=oldCCOption", "Value=", ENDITEM,
		"Name=numPassengers", "Value=1", ENDITEM,
		"Name=seatType", "Value={typeSeat}", ENDITEM,
		"Name=seatPref", "Value={seatingPreference}", ENDITEM,
		"Name=outboundFlight", "Value={outboundFlight}", ENDITEM,
		"Name=advanceDiscount", "Value=0", ENDITEM,
		"Name=returnFlight", "Value=", ENDITEM,
		"Name=JSFormSubmit", "Value=off", ENDITEM,
		"Name=buyFlights.x", "Value=53", ENDITEM,
		"Name=buyFlights.y", "Value=8", ENDITEM,
		"Name=.cgifields", "Value=saveCC", ENDITEM,
		LAST);
	
	lr_end_transaction("payment", LR_AUTO);
	
	return 0;
}

see_all_itinerary() {
	
	lr_start_transaction("see_all_itinerary");
	
		web_reg_find("Text/IC=User wants the intineraries.",
		LAST);

		web_reg_find("TextPfx/IC=<B>{userFirstName} {userLastName}",
		"TextSfx/IC= 's Flight Transaction Summary</B>",
		LAST);

	
		web_add_auto_header("Sec-Fetch-User", 
			"?1");
	
		web_add_auto_header("Upgrade-Insecure-Requests", 
			"1");
	
		web_url("Itinerary Button", 
			"URL=http://localhost:1080/cgi-bin/welcome.pl?page=itinerary", 
			"TargetFrame=body", 
			"Resource=0", 
			"RecContentType=text/html", 
			"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=flights", 
			"Snapshot=t7.inf", 
			"Mode=HTML", 
			LAST);
	
	lr_end_transaction("see_all_itinerary", LR_AUTO);
	
	return 0;
}