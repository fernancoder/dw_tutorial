#include "GeographicalInformator.h"


const int MAX_COUNTRY_SIZE=512;

char oneCharNorm[] = {0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,
                                          0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,
                                          0x20,0x21,0x22,0x23,0x24,0x25,0x26,0x27,0x28,0x29,0x2A,0x2B,0x2C,0x2D,0x2E,0x2F,
                                          0x30,0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,0x39,0x3A,0x3B,0x3C,0x3D,0x3E,0x3F,
                                          0x40,0x41,0x42,0x43,0x44,0x45,0x46,0x47,0x48,0x49,0x4A,0x4B,0x4C,0x4D,0x4E,0x4F,
                                          0x50,0x51,0x52,0x53,0x54,0x55,0x56,0x57,0x58,0x59,0x5A,0x5B,0x5C,0x5D,0x5E,0x5F,
                                          0x60,0x41,0x42,0x43,0x44,0x45,0x46,0x47,0x48,0x49,0x4A,0x4B,0x4C,0x4D,0x4E,0x4F,
                                          0x50,0x51,0x52,0x53,0x54,0x55,0x56,0x57,0x58,0x59,0x5A,0x7B,0x7C,0x7D,0x4E,0x20};

int twoCharNorm[] = {0x41,0x41,0x41,0x41,0x41,0x41,0xC6,0xC7,0x45,0x45,0x45,0x45,0x55,0x55,0x55,0x55,
                             0xD0,0xD1,0x4F,0x4F,0x4F,0x4F,0x4F,0xD7,0xD8,0x55,0x55,0x55,0x55,0x59,0xDE,0xDF,
                             0x41,0x41,0x41,0x41,0x41,0x41,0xC6,0xC7,0x45,0x45,0x45,0x45,0x49,0x49,0x49,0x49,
                             0xD0,0xD1,0x4F,0x4F,0x4F,0x4F,0x4F,0xF7,0xD8,0x55,0x55,0x55,0x55,0x59,0xD0,0x59};

bool GeographicalInformator::verifyCountry(string country)
{
    country = normalizeCountry(country);
    return this->mapCountry.find(country) != this->mapCountry.end();
}

string GeographicalInformator::getCapital(string country)
{
    country = normalizeCountry(country);
    if ( !this->verifyCountry(country) )
	return string("");
    return this->mapCountry[country][3];
}

string GeographicalInformator::getArea(string country)
{
    country = normalizeCountry(country);
    if ( !this->verifyCountry(country) )
        return string("");
    return this->mapCountry[country][6];
}

string GeographicalInformator::getPopulation(string country)
{
    country = normalizeCountry(country);
    if ( !this->verifyCountry(country) )
        return string("");
    return this->mapCountry[country][5];
}

GeographicalInformator::GeographicalInformator()
{
    //continent, country, capital, percapita, population, area
    vector<string> vCountry;
    vCountry = stringToVector("Africa||Uganda|Kampala|1577|24699073|236040"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Africa||Marruecos|Rabat|4819|31167783|446550"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Africa|Sudán|Jartum|2849|37090298|2505810"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Africa|Gabón|Libreville|72514|1233353|267667"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Africa|Sierra Leona|Freetown|962|5614743|71740"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Africa|Senegal|Dakar|1.841|10589571|196190"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Africa|Somalia|Mogadiscio|600|7753310|637657"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Africa|Etiopía|Addis Abeba|858|67673031|1127127"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Africa|Guinea Ecuatorial|Malabo|17426|498144|28051"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Africa|Eritrea|Asmara|858|4465651|121320"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Africa|Egipto|El Cairo|4535|70712345|1001450"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Africa|Santo Tomé y Príncipe|Santo Tomé|1617|170372|1001"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Africa|Djibouti|Djibouti|2329|472810|23000"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Africa|Swazilandia|Mbabane (administrativa), Lobamba (legislativa)|5439|1123605|17363"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Africa|Chad|Yamena|1627|8997237|1284000"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Africa|Togo|Lomé|1708|5285501|56785"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Africa|Gambia|Banjul|2086|1455842|11300"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Africa|Guinea (República)|Conakry|2116|7775065|245857"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Africa|Guinea-Bissau|Bissau|748|1345479|36120"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Africa|Madagascar|Antananarivo|965|16473477|587040"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Africa|Mali|Bamako|1229|11340480|1240000"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Africa|Lesotho|Maseru|2159|2207954|30355"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Africa|Liberia|Monrovia|1057|3288198|111370"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Africa|Mauritania|Nuakchott|3206|2828858|1030700"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Africa|Mauricio|Port Louis|13508|1200206|2040"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Africa|Malawi|Lilongwe|645|10701824|118480"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Africa|Mozambique|Maputo|1478|19607519|801590"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Africa|Namibia|Windhoek|7854|1820916|825418"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Africa|Comores|Moroni|1950|614382|2170"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Africa|Níger|Niamey|899|10639744|1267000"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Africa|Nigeria|Abuja|1241|129934911|923768"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Africa|Kenya|Nairobi|1519|31138735|582650"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Africa|Libia|Trípoli|12146|5368585|1759540"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Africa|Zimbabwe|Harare|2534|11376676|390580"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Africa|Ruanda|Kigali|1428|7398074|26338"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Africa|Cabo Verde|Praia|6922|408760|4033"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Africa|Argelia|Argel|7612|32277942|2381740"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Africa|Burundi|Bujumbura|777|6373002|27830"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Africa|Benin|Porto-Novo (oficial), Cotonou (administrativa)|1219|6787625|112620"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Africa|Congo|Brazzaville|1424|2958448|342000"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Africa|República Centroafricana|Bangui|1168|3642739|622984"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Africa|Congo, R.D. (Anteriormente Zaire)|Kinshasa|700|55225478|2345410"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Africa|Túnez|Túnez|8809|9815644|163610"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Africa|Botswana|Gaborone|12131|1591232|600370"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Africa|Seychelles|Victoria|11838|80098|455"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Africa|Burkina Faso|Ouagadougou|1346|12603185|274200"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Africa|Tanzania|Dodoma (política), Dar es Salaam (comercial)|777|37187939|945087"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Africa|Zambia|Lusaka|974|9959037|752614"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Africa|Costa de Marfil|Abidján (oficial), Yamoussoukro (administrativa)|1548|16804784|322460"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Africa|Angola|Luanda|3558|10593171|1246700"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Africa|Camerún|Yaoundé|2507|16184748|475440"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Africa|Sudáfrica|Pretoria (administrativa), Ciudad del Cabo (legislativa), Bloemfontein (judicial)|12760|43647658|1219912"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Africa|Ghana|Accra|2781|20244154|239460"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("América|México|Ciudad de México|10604|103400165|1972550"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("América|Canadá|Ottawa|35779|31902268|9976140"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("América|Puerto Rico (USA)|San Juan|18600|3957988|9104"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("América|Paraguay|Asunción|5061|5884491|406750"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("América|Haití|Puerto Príncipe|1841|7063722|27750"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("América|Panamá|Panamá|7593|2882329|78200"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("América|Jamaica|Kingston|4615|2680029|10991"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("América|Antigua y Barbuda|Saint John's|11929|67448|443"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("América|Argentina|Buenos Aires|14838|36260130|2791810"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("América|Venezuela|Caracas|6467|24287670|912050"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("América|San Vicente y las Granadinas|Kingstown|7958|116394|389"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("América|San Cristóbal y Nevis|Basseterre|15536|38736|261"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("América|Uruguay|Montevideo|11378|3386575|176220"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("América|Estados Unidos|Washington, DC|43236|280562489|9629091"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("América|Barbados|Bridgetown|18381|276607|431"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("América|Nicaragua|Managua|3770|5023818|129494"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("América|Honduras|Tegucigalpa|3131|6560608|112090"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("América|Perú|Lima|6289|27949639|1285220"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("América|Bahamas|Nassau|21049|300529|13940"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("América|Santa Lucía|Castries|6942|160145|616"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("América|Belice|Belmopan|8055|262999|22966"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("América|Chile|Santiago|12737|15498930|756950"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("América|Ecuador|Quito|4466|13447494|283560"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("América|El Salvador|San Salvador|4620|6353681|21040"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("América|República Dominicana|Santo Domingo|8018|8721594|48730"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("América|Dominica|Roseau|6843|70158|754"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("América|Brasil|Brasilia|8917|176029560|8511965"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("América|Granada|Saint George's|8863|89211|344"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("América|Cuba|La Habana|3500|11224321|110860"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("América|Trinidad y Tobago|Puerto España|16020|1163724|5128"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("América|Guatemala|Ciudad de Guatemala|4266|13314079|108890"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("América|Colombia|Santa Fe de Bogotá|7646|41008227|1138910"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("América|Surinam|Paramaribo|5902|436494|163270"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("América|Bolivia|La Paz (administrativa), Sucre (judicial)|2791|8445134|1098580"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("América|Costa Rica|San José|10747|3834934|51100"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("América|Guyana|Georgetown|4852|698209|214970"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Asia|Yemen|Sanaa|752|18701257|527970"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Asia|Vietnam|Hanoi|3255|81098416|329560"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Asia|Mongolia|Ulan Bator|2322|2694432|1565000"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Asia|Myanmar (Birmania)|Rangún (Yangón)|1753|42238224|678500"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Asia|Tailandia|Bangkok|8877|62354402|514000"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Asia|Maldivas|Malé|8284|320165|300"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Asia|Timor Oriental|Dili|1898|952618|15007"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Asia|Malasia|Kuala Lumpur (oficial), Putrajaya (administrativa)|11915|22662365|329750"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Asia|Arabia Saudita|Riad (Real), Jiddah (administrativa)|15873|23513330|1960582"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Asia|Qatar|Doha|32596|793341|11437"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Asia|Turquía|Ankara|8385|67308928|780580"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Asia|Pakistán|Islamabad|2830|147663429|803940"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Asia|Taiwan|Taipei|29244|22548009|35980"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Asia|Omán|Mascate|17906|2713462|212460"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Asia|Nepal|Katmandú|1761|25873917|140800"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Asia|Singapur|Singapur|29743|7303334|1092"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Asia|Siria|Damasco|3976|17155814|185180"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Asia|Filipinas|Manila|5160|84525639|300000"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Asia|Líbano|Beirut|6933|3677780|10400"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Asia|Indonesia|Yakarta|4753|231328092|1919440"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Asia|Kuwait|Kuwait|16593|2111561|17820"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Asia|Corea del Sur|Seúl|21877|48324000|98480"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Asia|Corea del Norte|Pyongyang|1700|22224195|120540"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Asia|Camboya|Phnom Penh|2534|12775324|181040"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Asia|Israel|Jerusalén|24357|6029529|20770"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Asia|Bahrein|Manama|22706|656397|678"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Asia|Brunei|Bandar Seri Begawan|25511|350898|5770"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Asia|India|Nueva Delhi|3550|1045845226|3287590"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Asia|Jordania|Ammán|5197|5307470|92300"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Asia|Iraq|Bagdad|3400|24001816|437072"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Asia|China|Pekín|8004|1284303705|9596960"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Asia|Bangladesh|Dacca|2136|133376684|144000"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Asia|Laos|Vientiane|2260|5777180|236800"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Asia|Emiratos Árabes Unidos|Abu Dhabi|27610|2445989|82880"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Asia|Afganistán|Kabul|1440|27755775|647500"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Asia|Irán|Teherán|8441|66622704|1648000"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Asia|Japón|Tokio|31866|126974628|377835"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Asia|Sri Lanka|Colombo (administrativa), Sri Jayewardenapura Kotte (legislativa)|4705|19576783|65610"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Asia|Bután|Thimphu|4437|2094176|47000"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Europa|Malta|La Valetta|20365|397499|316"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Europa|Andorra|Andorra la Vella|24000|68403|468"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Europa|España|Madrid|27542|44108530|504782"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Europa|Francia|París|30150|59765983|547030"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Europa|República Checa|Praga|19428|10256760|78866"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Europa|Eslovenia|Liubliana|23159|1932917|20273"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Europa|Alemania|Berlín|31571|83251851|357021"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Europa|Dinamarca|Copenhague|36074|5368854|43094"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Europa|Finlandia|Helsinki|32822|5183545|337030"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Europa|San Marino|San Marino|34600|27730|61"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Europa|Eslovaquia|Bratislava|17239|5422366|48845"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Europa|Chipre|Nicosia|22276|767314|9250"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Europa|Armenia|Ereván|4516|3330099|29800"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Europa|Austria|Viena|34803|8169929|83858"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Europa|Uzbekistán|Tashkent|1983|25563441|447400"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Europa|Azerbaiyán|Bakú|5895|7798497|86600"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Europa|Bosnia y Herzegovina|Sarajevo|6456|3964388|51129"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Europa|Rumania|Bucarest|9446|21698181|238391"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Europa|Ucrania|Kiev|7816|48396470|603700"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Europa|Bélgica|Bruselas|32500|10274595|30510"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Europa|Bulgaria|Sofía|10003|7621337|110910"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Europa|Santa Sede|Ciudad del Vaticano||900|0"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Europa|Bielorrusia|Minsk|8230|10335382|207600"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Europa|Turkmenistán|Ashgabat|8663|4688963|488100"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Europa|Suiza|Berna|33794|7301994|41290"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Europa|Tayikistán|Dushanbe|1506|6719567|143100"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Europa|Albania|Tirana|5818|3544841|28748"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Europa|Suecia|Estocolmo|31264|8876744|449964"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Europa|Reino Unido|Londres|31585|59778002|244820"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Europa|Noruega|Oslo|44342|4525116|324220"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Europa|Holanda|Amsterdam (oficial), La Haya (administrativa)|32062|16067754|41526"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Europa|Kirguistán|Bishkek|2224|4822166|198500"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Europa|Hungría|Budapest|17821|10075034|93030"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Europa|Kazajistán|Astana|9134|16741519|2717300"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Europa|Estonia|Talin|17802|1415681|45226"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Europa|Liechtenstein|Vaduz|25000|32842|160"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Europa|Lituania|Vilna|15443|3601138|65200"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Europa|República de Macedonia|Skopje|8175|2054800|25333"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Europa|Luxemburgo|Luxemburgo|72855|448569|2586"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Europa|Montenegro|Podgorica|3976|500000|13812"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Europa|Moldavia|Chisinau (Kishinev)|2708|4434547|33843"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Europa|Mónaco|Mónaco|27000|31987|2"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Europa|Italia|Roma|29406|57715625|301230"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Europa|Islandia|Reykjavík|37296|279384|103000"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Europa|Georgia|Tbilisi|3755|4960951|69700"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Europa|Grecia|Atenas|23519|10645343|131940"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Europa|Croacia|Zagreb|13062|4390751|56542"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Europa|Rusia|Moscú|11904|144978573|17075200"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Europa|Serbia|Belgrado|5713|9780000|88361"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Europa|Irlanda|Dublín|42859|3883159|70280"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Europa|Portugal|Lisboa|19949|10084245|92391"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Europa|Letonia|Riga|13875|2366515|64589"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Europa|Polonia|Varsovia|13797|38625478|312685"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Oceanía|Australia|Canberra|32127|19546792|7686850"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Oceanía|Nueva Zelanda|Wellington|25655|3908037|268680"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Oceanía|Micronesia|Palikir|3900|135869|702"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Oceanía|Samoa|Apia|6581|178631|2944"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Oceanía|Vanuatu|Port Vila|3424|196178|12200"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Oceanía|Niue|Alofi|3508|2166|260"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Oceanía|Islas Marshall|Majuro|2300|73630|181"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Oceanía|Islas Salomón|Honiara|1975|494786|28450"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Oceanía|Fiji|Suva|6610|856346|18270"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Oceanía|Nauru|Yaren|5000|12329|21"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Oceanía|Tonga|Nuku'alofa|8304|106137|748"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Oceanía|Papúa Nueva Guinea|Port Moresby|2460|5172033|462840"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Oceanía|Palau|Koror|5800|19409|458"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Oceanía|Kiribati|Tarawa|2379|96335|811"); mapCountry[vCountry[0]] = vCountry;
    vCountry = stringToVector("Oceanía|Tuvalu|Funafuti|1100|11146|26"); mapCountry[vCountry[0]] = vCountry;
}

GeographicalInformator::~GeographicalInformator()
{

}

vector<string> GeographicalInformator::stringToVector(string data)
{
    vector<string> vData;
    char delim = '|';

    vData.push_back("NORMAL");

    string buf = "";
    int i = 0;
    while (i < data.length()) {
        if (data[i] != delim)
            buf += data[i];
        else if (buf.length() > 0) {
            vData.push_back(buf);
            buf = "";
        }
        i++;
    }
    if (!buf.empty())
        vData.push_back(buf);

    vData[0] = normalizeCountry(vData[2]);

    return vData;
}

int GeographicalInformator::utf8CharSize (const unsigned char c)
{
        if ((c & 0x80) == 0x00) return 1;
        if ((c & 0xE0) == 0xC0) return 2;
        if ((c & 0xF0) == 0xE0) return 3;
        return 0;
}

string GeographicalInformator::normalizeCountry(string country)
{
    unsigned char NormalizedCountry[MAX_COUNTRY_SIZE];
    unsigned char *pNormalizedCountry = NormalizedCountry;
    int curSize = 0;

    const unsigned char *pCountry = (const unsigned char *)country.c_str();
    while ( *pCountry )
    {
        switch ( utf8CharSize(*pCountry) )
        {
            case 0: //Caracter no admitido
                pCountry++;
            break;
            case 1:
                *pNormalizedCountry++ = oneCharNorm[(int)*pCountry++];
                curSize++;
            break;
            case 2:
                if ( (int)*pCountry == 0xC3 && ((int)*(pCountry+1)) >= 0x80 )
                {
                    *pNormalizedCountry++ = twoCharNorm[((int)*(pCountry+1))-0x80];
                    curSize++;
                }
                pCountry++;
                if ( *pCountry )
                    pCountry++;
            break;
            case 3:
                pCountry += 3;
            break;
        }
        if ( curSize + 5 >= MAX_COUNTRY_SIZE )
            break;
    }

    *pNormalizedCountry = '\0';
    return string((const char*)NormalizedCountry);
}

void GeographicalInformator::trace()
{
    for (map<string, vector<string> >::iterator iter = mapCountry.begin(); iter != mapCountry.end(); iter++) 
    {
        cout << iter->first << endl;
    }
}
