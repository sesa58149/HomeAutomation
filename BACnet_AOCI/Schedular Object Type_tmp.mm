<map version="freeplane 1.2.0">
<!--To view this file, download free mind mapping software Freeplane from http://freeplane.sourceforge.net -->
<node TEXT="BACnet Object" ID="ID_1723255651" CREATED="1283093380553" MODIFIED="1369388379952" STYLE="bubble">
<icon BUILTIN="very_positive"/>
<hook NAME="MapStyle" zoom="0.909" layout="OUTLINE">

<map_styles>
<stylenode LOCALIZED_TEXT="styles.root_node">
<stylenode LOCALIZED_TEXT="styles.predefined" POSITION="right">
<stylenode LOCALIZED_TEXT="default" MAX_WIDTH="600" COLOR="#000000" STYLE="as_parent">
<font NAME="SansSerif" SIZE="10" BOLD="false" ITALIC="false"/>
</stylenode>
<stylenode LOCALIZED_TEXT="defaultstyle.details"/>
<stylenode LOCALIZED_TEXT="defaultstyle.note"/>
<stylenode LOCALIZED_TEXT="defaultstyle.floating">
<edge STYLE="hide_edge"/>
<cloud COLOR="#f0f0f0" SHAPE="ROUND_RECT"/>
</stylenode>
</stylenode>
<stylenode LOCALIZED_TEXT="styles.user-defined" POSITION="right">
<stylenode LOCALIZED_TEXT="styles.topic" COLOR="#18898b" STYLE="fork">
<font NAME="Liberation Sans" SIZE="10" BOLD="true"/>
</stylenode>
<stylenode LOCALIZED_TEXT="styles.subtopic" COLOR="#cc3300" STYLE="fork">
<font NAME="Liberation Sans" SIZE="10" BOLD="true"/>
</stylenode>
<stylenode LOCALIZED_TEXT="styles.subsubtopic" COLOR="#669900">
<font NAME="Liberation Sans" SIZE="10" BOLD="true"/>
</stylenode>
<stylenode LOCALIZED_TEXT="styles.important">
<icon BUILTIN="yes"/>
</stylenode>
</stylenode>
<stylenode LOCALIZED_TEXT="styles.AutomaticLayout" POSITION="right">
<stylenode LOCALIZED_TEXT="AutomaticLayout.level.root" COLOR="#000000">
<font SIZE="18"/>
</stylenode>
<stylenode LOCALIZED_TEXT="AutomaticLayout.level,1" COLOR="#0033ff">
<font SIZE="16"/>
</stylenode>
<stylenode LOCALIZED_TEXT="AutomaticLayout.level,2" COLOR="#00b439">
<font SIZE="14"/>
</stylenode>
<stylenode LOCALIZED_TEXT="AutomaticLayout.level,3" COLOR="#990000">
<font SIZE="12"/>
</stylenode>
<stylenode LOCALIZED_TEXT="AutomaticLayout.level,4" COLOR="#111111">
<font SIZE="10"/>
</stylenode>
</stylenode>
</stylenode>
</map_styles>
</hook>
<hook NAME="AutomaticEdgeColor" COUNTER="10"/>
<hook NAME="accessories/plugins/AutomaticLayout.properties" VALUE="ALL"/>
<node TEXT="Scheduler Object" POSITION="right" ID="ID_1843969723" CREATED="1369385698054" MODIFIED="1369388368579" STYLE="bubble">
<edge COLOR="#7c007c"/>
<node TEXT="Object_Identifier" ID="ID_1581644739" CREATED="1369376521835" MODIFIED="1369388368605" STYLE="bubble">
<node TEXT="Uint32" ID="ID_1172756654" CREATED="1369376921029" MODIFIED="1369388368607" STYLE="bubble"/>
</node>
<node TEXT="Object_Name" ID="ID_1715875663" CREATED="1369376671510" MODIFIED="1369388368608" STYLE="bubble">
<node TEXT="Char String" ID="ID_1107927486" CREATED="1369376933910" MODIFIED="1369388368611" STYLE="bubble"/>
</node>
<node TEXT="Object_Type" ID="ID_801320467" CREATED="1369376685589" MODIFIED="1369388368612" STYLE="bubble">
<node TEXT="Uint32" ID="ID_1860087535" CREATED="1369376954023" MODIFIED="1369388368614" STYLE="bubble"/>
</node>
<node TEXT="Present_Value" ID="ID_1228878954" CREATED="1369376694281" MODIFIED="1369388368615" STYLE="bubble">
<node TEXT="Any" ID="ID_1755009017" CREATED="1369376969270" MODIFIED="1369388368617" STYLE="bubble"/>
</node>
<node TEXT="Description" ID="ID_1012920035" CREATED="1369376715750" MODIFIED="1369388368617" STYLE="bubble">
<node TEXT="Char String" ID="ID_1807976156" CREATED="1369376986193" MODIFIED="1369388368619" STYLE="bubble"/>
</node>
<node TEXT="Effective_Period" ID="ID_1217611200" CREATED="1369376725932" MODIFIED="1369388368619" STYLE="bubble">
<node TEXT="BACnetDateRange" ID="ID_1381425453" CREATED="1369377101380" MODIFIED="1369388368622" STYLE="bubble">
<icon BUILTIN="positive"/>
<node TEXT="StartDate -Date" ID="ID_541675745" CREATED="1369377378555" MODIFIED="1369388368623" STYLE="bubble"/>
<node TEXT="EndDate- Date" ID="ID_761414393" CREATED="1369377935532" MODIFIED="1369388368623" STYLE="bubble"/>
</node>
</node>
<node TEXT="Weekly_schedule" ID="ID_217220878" CREATED="1369376744856" MODIFIED="1369388368624" STYLE="bubble">
<node TEXT="BACnetDailySchedule  Mon...Sun" ID="ID_1747319509" CREATED="1369377163425" MODIFIED="1369388368626" STYLE="bubble">
<icon BUILTIN="positive"/>
<node TEXT="BACnetTimeValues - List" ID="ID_1850107110" CREATED="1369379830972" MODIFIED="1369379888294">
<node TEXT="Time" ID="ID_1974494742" CREATED="1369379888304" MODIFIED="1369379895096"/>
<node TEXT="Value --- Any" ID="ID_1499775933" CREATED="1369379895386" MODIFIED="1369379913141"/>
</node>
</node>
</node>
<node TEXT="Exception_Schnedule   Array of N element  -- 3 ?" ID="ID_1068428799" CREATED="1369376778766" MODIFIED="1369388368626" STYLE="bubble">
<node TEXT="BACnetSpecialEvent" ID="ID_637561915" CREATED="1369377195932" MODIFIED="1369388368631" STYLE="bubble">
<icon BUILTIN="positive"/>
<node TEXT="period" ID="ID_393389599" CREATED="1369377589498" MODIFIED="1369388368635" STYLE="bubble">
<node TEXT="Choice" ID="ID_1313615018" CREATED="1369377695890" MODIFIED="1369388368638" STYLE="bubble">
<node TEXT="CalenderReference ----BACnetObjectIdentyfier" ID="ID_999830227" CREATED="1369377705846" MODIFIED="1369388368641" STYLE="bubble">
<icon BUILTIN="go"/>
<node TEXT="Uint32" ID="ID_812441421" CREATED="1369377868867" MODIFIED="1369388368642" STYLE="bubble"/>
</node>
<node TEXT="BACnetCalenderEntry" ID="ID_909898512" CREATED="1369377743130" MODIFIED="1369388368643" STYLE="bubble">
<icon BUILTIN="stop"/>
<node TEXT="Choice" ID="ID_1302854277" CREATED="1369385496024" MODIFIED="1369388368511" STYLE="bubble">
<node TEXT="date ---Date" ID="ID_1498962768" CREATED="1369377874692" MODIFIED="1369386855593"/>
<node TEXT="dateRange ---BACnetDateRange" ID="ID_1694011218" CREATED="1369378000548" MODIFIED="1369386866730">
<node TEXT="date" ID="ID_1954786709" CREATED="1369378067879" MODIFIED="1369378070757"/>
<node TEXT="date" ID="ID_1150873579" CREATED="1369378071089" MODIFIED="1369378073176"/>
</node>
<node TEXT="BACnetWeekNDay" ID="ID_594379598" CREATED="1369378013646" MODIFIED="1369378050579">
<node TEXT="First Octet" ID="ID_765393555" CREATED="1369378743134" MODIFIED="1369378786937">
<node TEXT="Month - (1 to 14) :-&gt;    1= Jan&#xa;                                    13= Odd Month&#xa;                                    14=Even Month&#xa;                                     FF=Any Month" ID="ID_1422281249" CREATED="1369378816352" MODIFIED="1369379596741">
<icon BUILTIN="addition"/>
</node>
</node>
<node TEXT="Second Octet" ID="ID_728002435" CREATED="1369378755931" MODIFIED="1369378771799">
<node TEXT="WeekOfMonth(1-6)&#xa;                                    1=Days numbered 1-7&#xa;                                    2=Days numbered 8-14&#xa;                                    3=Days numbered 15-21&#xa;                                    4=Days numbered 22-28&#xa;                                    5=Days numbered 29-31&#xa;                                    6=last 7 days of this month&#xa;                                    FF=Any week of this Month" ID="ID_1572597379" CREATED="1369379294696" MODIFIED="1369379488830">
<icon BUILTIN="addition"/>
</node>
</node>
<node TEXT="Third Octet" ID="ID_520210840" CREATED="1369378773147" MODIFIED="1369378779989">
<node TEXT="DayOfWeek (1...7)&#xa;                                    1= Monday&#xa;                                    7=Sunday&#xa;                                    FF=Any day of week" ID="ID_342721502" CREATED="1369379505882" MODIFIED="1369379578882">
<icon BUILTIN="addition"/>
</node>
</node>
</node>
</node>
</node>
</node>
</node>
<node TEXT="BACnetTimeValues- List   ...20" ID="ID_274963480" CREATED="1369377758434" MODIFIED="1369388368644" STYLE="bubble">
<node TEXT="Time" ID="ID_570184582" CREATED="1369379929610" MODIFIED="1369388368646" STYLE="bubble"/>
<node TEXT="Value ---Any" ID="ID_1593355762" CREATED="1369379933688" MODIFIED="1369388368647" STYLE="bubble"/>
</node>
<node TEXT="EventPriority-Uint32" ID="ID_1044685411" CREATED="1369377831841" MODIFIED="1369388368648" STYLE="bubble"/>
</node>
</node>
<node TEXT="Schedule_Default" ID="ID_936939385" CREATED="1369376805122" MODIFIED="1369388368649" STYLE="bubble">
<node TEXT="Any" ID="ID_1421450873" CREATED="1369377220329" MODIFIED="1369377223971"/>
</node>
<node TEXT="List_Of_Object_Property_References" ID="ID_1118216245" CREATED="1369376824499" MODIFIED="1369388368651" STYLE="bubble">
<node TEXT="BACnetDeviceObjectPropertyReference" ID="ID_78258443" CREATED="1369377233312" MODIFIED="1369377256035">
<node TEXT="BACnetObjectIdentifier ---Uint32" ID="ID_1403218248" CREATED="1369380024794" MODIFIED="1369380197193"/>
<node TEXT="BACnetPropertyIdentifier ---Uint32" ID="ID_1870347636" CREATED="1369380063882" MODIFIED="1369380206422"/>
<node TEXT="PeroperyArrayIndex -- Optional" ID="ID_388924592" CREATED="1369380128412" MODIFIED="1369380149379"/>
<node TEXT="DeviceIdentifier --- Uint32 --- Optional" ID="ID_284324305" CREATED="1369380149737" MODIFIED="1369380219203"/>
</node>
</node>
<node TEXT="Priority_For_Writing" ID="ID_585575095" CREATED="1369376844900" MODIFIED="1369388368652" STYLE="bubble">
<node TEXT="Uint32" ID="ID_1580009255" CREATED="1369377286649" MODIFIED="1369388368654" STYLE="bubble"/>
</node>
<node TEXT="Status_Flags" ID="ID_150887238" CREATED="1369376867148" MODIFIED="1369388368654" STYLE="bubble">
<node TEXT="BACnetStatusFlag" ID="ID_252403424" CREATED="1369377307923" MODIFIED="1369388368655" STYLE="bubble"/>
</node>
<node TEXT="Reliability" ID="ID_692744824" CREATED="1369376878257" MODIFIED="1369388368656" STYLE="bubble">
<node TEXT="BACnetReliabilityFlag" ID="ID_243768648" CREATED="1369377321904" MODIFIED="1369388368657" STYLE="bubble"/>
</node>
<node TEXT="Out_Of_Service" ID="ID_252798278" CREATED="1369376895292" MODIFIED="1369388368658" STYLE="bubble">
<node TEXT="Boolen" ID="ID_79922473" CREATED="1369377351352" MODIFIED="1369388368659" STYLE="bubble"/>
</node>
<node TEXT="Profile_Name" ID="ID_379571627" CREATED="1369376903827" MODIFIED="1369388368659" STYLE="bubble">
<node TEXT="Char String" ID="ID_1118307147" CREATED="1369377358043" MODIFIED="1369377368147"/>
</node>
</node>
<node TEXT="Calender Object" POSITION="left" ID="ID_1378574482" CREATED="1369380929929" MODIFIED="1369388368660" STYLE="bubble">
<edge COLOR="#007c00"/>
<node TEXT="Object_Identifier --- Uint32" ID="ID_1604095198" CREATED="1369380974179" MODIFIED="1369388368664" STYLE="bubble"/>
<node TEXT="Object_Name --- Char String" ID="ID_1827255768" CREATED="1369380991558" MODIFIED="1369388368665" STYLE="bubble"/>
<node TEXT="Object_Type -- Uint32" ID="ID_1619491522" CREATED="1369381025750" MODIFIED="1369388368666" STYLE="bubble"/>
<node TEXT="Description -- Char String" ID="ID_1552250878" CREATED="1369381042202" MODIFIED="1369388368667" STYLE="bubble"/>
<node TEXT="Present_Value -- Boolean" ID="ID_495690592" CREATED="1369381059611" MODIFIED="1369388368668" STYLE="bubble"/>
<node TEXT="Data_List --- BACnetCalenderEntry -- 10 ?" ID="ID_968046761" CREATED="1369377695890" MODIFIED="1369388368669" STYLE="bubble">
<node TEXT="Choice" ID="ID_669455719" CREATED="1369385496024" MODIFIED="1369385674387">
<node TEXT="date" ID="ID_1906041909" CREATED="1369377874692" MODIFIED="1369378000226"/>
<node TEXT="BACnetDateRange" ID="ID_1675702280" CREATED="1369378000548" MODIFIED="1369378012701">
<node TEXT="date" ID="ID_1156858525" CREATED="1369378067879" MODIFIED="1369378070757"/>
<node TEXT="date" ID="ID_385256719" CREATED="1369378071089" MODIFIED="1369378073176"/>
</node>
<node TEXT="BACnetWeekNDay" ID="ID_309809845" CREATED="1369378013646" MODIFIED="1369378050579">
<node TEXT="First Octet" ID="ID_1496855457" CREATED="1369378743134" MODIFIED="1369378786937">
<node TEXT="Month - (1 to 14) :-&gt;    1= Jan&#xa;                                    13= Odd Month&#xa;                                    14=Even Month&#xa;                                     FF=Any Month" ID="ID_560627907" CREATED="1369378816352" MODIFIED="1369379596741">
<icon BUILTIN="addition"/>
</node>
</node>
<node TEXT="Second Octet" ID="ID_1461615549" CREATED="1369378755931" MODIFIED="1369378771799">
<node TEXT="WeekOfMonth(1-6)&#xa;                                    1=Days numbered 1-7&#xa;                                    2=Days numbered 8-14&#xa;                                    3=Days numbered 15-21&#xa;                                    4=Days numbered 22-28&#xa;                                    5=Days numbered 29-31&#xa;                                    6=last 7 days of this month&#xa;                                    FF=Any week of this Month" ID="ID_1433091092" CREATED="1369379294696" MODIFIED="1369379488830">
<icon BUILTIN="addition"/>
</node>
</node>
<node TEXT="Third Octet" ID="ID_1189080065" CREATED="1369378773147" MODIFIED="1369378779989">
<node TEXT="DayOfWeek (1...7)&#xa;                                    1= Monday&#xa;                                    7=Sunday&#xa;                                    FF=Any day of week" ID="ID_109725657" CREATED="1369379505882" MODIFIED="1369379578882">
<icon BUILTIN="addition"/>
</node>
</node>
</node>
</node>
</node>
<node TEXT="Profile_Name -- Char String" ID="ID_1173593848" CREATED="1369381124665" MODIFIED="1369388368670" STYLE="bubble"/>
</node>
</node>
</map>
