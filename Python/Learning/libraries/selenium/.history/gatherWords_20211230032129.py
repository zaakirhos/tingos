import pymongo
# from selenium import webdriver
# from selenium.webdriver.support.ui import WebDriverWait
# from selenium.webdriver.common.by import By
# from selenium.webdriver.support import expected_conditions as EC
# import time

# words = []

# driver = webdriver.Chrome()

# main = driver.get('https://app.memrise.com/course/254000/1500-advanced-english-words/')

# cookie = driver.find_element_by_xpath('/html/body/div[1]/a')
# cookie.click()
# # section = driver.find_element_by_xpath(
# #     '//*[@id="content"]/div/div/div[1]/div/a[11]')
# # time.sleep(3)
# # section.click()

# try:
#     for i in range(50):
#         section = driver.find_element_by_xpath(
#             f'//*[@id="content"]/div/div/div[1]/div/a[{i+1}]')
#         section.click()
#         # time.sleep(5)
#         for j in range(30):
#             word = driver.find_element_by_xpath(f'//*[@id="content"]/div/div/div[2]/div[{4+j}]/div[3]/div').text
#             defi = driver.find_element_by_xpath(f'//*[@id="content"]/div/div/div[2]/div[{4+j}]/div[4]/div').text
#             word_and_definition = {
#                 'word': word,
#                 'definition': defi
#             }
#             words.append(word_and_definition)
#         #click the browser backward once.
#         # time.sleep(1)
#         driver.execute_script("window.history.go(-1)")
# except Exception as e:
#     print("Failed")

# finally:
#     client = pymongo.MongoClient(
#         'mongodb+srv://zakir:mongo123@cluster0.abqkq.mongodb.net/zakir?retryWrites=true&w=majority')

#     db = client.get_database('pool')
#     wordC = db.words
#     wordC.delete_many({ })
#     wordC.insert_one({'words': words, 'count': len(words)})
    
#     print(len(words))
#     driver.close()


# client = pymongo.MongoClient(
#         'mongodb+srv://zakir:mongo123@cluster0.abqkq.mongodb.net/zakir?retryWrites=true&w=majority')

# db = client.get_database('pool')
# wordC = db.words
# print(wordC.count_documents({}))
# # wordC.insert_one({'words': words, 'count': len(words)})
# #     print(len(words))

token = """B2
absorb v.
abstract adj.
accent n.
accidentally adv.
accommodate v.
accommodation n.
accomplish v.
accountant n.
accuracy n.
accurately adv.
acid n.
acre n.
activate v.
addiction n.
additionally adv.
adequate adj.
adequately adv.
adjust v.
affordable adj.
aged adj.
agriculture n.
AIDS n.
alien n.
alongside prep.
altogether adv.
ambitious adj.
ambulance n.
amusing adj.
analyst n.
ancestor n.
animation n.
annually adv.
anticipate v.
anxiety n.
apology n.
applicant n.
appropriately adv.
arrow n.
artwork n.
asset n.
assign v.
assistance n.
assumption n.
assure v.
astonishing adj.
athletic adj.
attachment n.
audio adj.
awareness n.
awkward adj.
badge n.
balanced adj.
ballet n.
balloon n.
barely adv.
bargain n.
basement n.
basket n.
bat n.
beneficial adj.
beside prep.
besides prep., adv.
bias n.
bid n., v.
biological adj.
blanket n.
blow n.
bold adj.
bombing n.
boost v., n.
bound adj.
brick n.
briefly adv.
broadcaster n.
broadly adv.
buck n.
bug n.
cabin n.
canal n.
candle n.
carbon n.
castle n. B2
casual adj.
cave n.
certainty n.
certificate n.
challenging adj.
championship n.
charming adj.
chase v., n.
cheek n.
cheer v., n.
chop v.
circuit n.
civilization n.
clarify v.
classify v.
cliff n.
clinic n.
clip n.
coincidence n.
collector n.
colony n.
colorful adj.
comic adj., n.
commander n.
comparative adj.
completion n.
compose v.
composer n.
compound n.
comprehensive adj.
comprise v.
compulsory adj.
concrete adj., n.
confess v.
confusion n.
consequently adv.
conservation n.
considerable adj.
considerably adv.
consistently adv.
conspiracy n.
consult v.
consultant n.
consumption n.
controversial adj.
controversy n.
convenience n.
convention n.
conventional adj.
convey v.
convincing adj.
cop n.
cope v.
corporation n.
corridor n.
counter (long flat surface) n.
coverage n.
cowboy n.
crack v., n.
craft n.
creativity n.
critically adv.
cruise n., v.
cue n.
curious adj.
curriculum n.
cute adj.
dairy n., adj.
dare v.
darkness n.
database n.
deadline n.
deadly adj.
dealer n.
deck n.
defender n.
delete v.
delighted adj. B2
democracy n.
democratic adj.
demonstration n.
depart v.
dependent adj.
deposit n., v.
depression n.
derive v.
desperately adv.
destruction n.
determination n.
devote v.
differ v.
dime n.
disability n.
disabled adj.
disagreement n.
disappoint v.
disappointment n.
discourage v.
disorder n.
distant adj.
distinct adj.
distinguish v.
distract v.
disturb v.
dive v., n.
diverse adj.
diversity n.
divorce n., v.
dominant adj.
donation n.
dot n.
dramatically adv.
drought n.
dull adj.
dump v.
duration n.
dynamic adj.
eager adj.
economics n.
economist n.
editorial adj.
efficiently adv.
elbow n.
electronics n.
elegant adj.
elementary adj.
eliminate v.
embrace v.
emission n.
emotionally adv.
empire n.
enjoyable adj.
entertaining adj.
entrepreneur n.
envelope n.
equip v.
equivalent n., adj.
era n.
erupt v.
essentially adv.
ethic n.
ethnic adj.
evaluation n
evident adj.
evolution n.
evolve v.
exceed v.
exception n.
excessive adj.
exclude v.
exotic adj.
expansion n.
expedition n.
expertise n.
exploit v.
exposure n.
extension n.
extensive adj.
extensively adv.
extract n.
fabric n.
fabulous adj.
faculty n.
failed adj.
fake adj.
fame n.
fantasy n.
fare n.
firefighter n.
firework n.
firm adj.
firmly adv.
flavor n.
fond adj.
fool n.
forbid v.
forecast n., v.
format n.
formation n.
formerly adv.
fortunate adj.
forum n.
fossil n.
foundation n.
founder n.
fraction n.
fragment n.
framework n.
fraud n.
freely adv.
frequent adj.
fulfill v.
full-time adj./adv.
fundamentally adv.
furious adj.
gallon n.
gaming n.
gay adj.
gender n.
gene n.
genetic adj.
genius n.
genuine adj.
genuinely adv.
gesture n.
globalization n.
globe n.
golden adj.
goodness n.
gorgeous adj.
graphic adj.
graphics n.
greatly adv.
greenhouse n.
guideline n.
habitat n.
harbor n.
headquarters n.
heal v.
healthcare n.
helmet n.
hence adv.
herb n.
hidden adj.
hilarious adj.
hip n.
historian n.
homeless adj.
honesty n.
honey n.
hook n.
hopefully adv.
hunger n.
hypothesis n.
icon n.
ID n.
identical adj.
illusion n.
immigration n.
immune adj.
implement v.
implication n.
incentive n.
incorporate v.
incorrect adj.
independence n.
index n.
indication n.
inevitable adj.
inevitably adv.
infer v.
inflation n.
info n.
infrastructure n.
inhabitant n.
inherit v.
ink n.
innovation n.
innovative adj.
input n.
insert v.
inspector n.
installation n.
instant adj.
instantly adv.
integrate v.
intellectual adj.
interact v.
interaction n.
interpretation n.
interval n.
invade v.
invasion n.
investor n.
isolate v.
isolated adj.
jail n., v.
jet n.
joint adj., n.
journalism n.
jury n.
kindergarten n.
kit n.
ladder n.
landing n.
lane n.
lately adv.
legend n.
lens n.
lifetime n.
lighting n.
likewise adv.
limitation n.
literally adv.
literary adj.
litter n.
logo n.
lottery n.
loyal adj.
lyric n.
makeup n.
making n.
manufacture v.
manufacturing n.
marathon n.
margin n.
marker n.
martial adj.
mate n., v.
mechanic n.
mechanical adj.
mechanism n.
medal n.
medication n.
membership n.
memorable adj.
metaphor n.
miner n.
miserable adj.
mode n.
modest adj.
monster n.
monthly adj.
monument n.
moreover adv.
mortgage n.
mosque n.
mosquito n.
motion n.
motivate v.
motivation n.
moving adj.
myth n.
naked adj.
nasty adj.
navigation n.
nearby adj., adv.
necessity n.
negotiate v.
negotiation n.
neutral adj.
newly adv.
nickel n.
norm n.
notebook n.
novelist n.
nowadays adv.
nursing adj.
nutrition n.
obesity n.
observer n.
obstacle n.
occupation n.
occupy v.
offender n.
ongoing adj.
openly adv.
opera n.
operator n.
optimistic adj.
orchestra n.
organic adj.
outfit n.
output n.
outstanding adj.
overcome v.
overnight adv.
ownership n.
oxygen n.
packet n.
palm n.
panic n.
parade n.
parallel adj., n.
participation n.
partnership n.
part-time adj./adv.
passionate adj.
password n.
patch n.
patience n.
pause v., n.
peer n.
penalty n.
perceive v.
perception n.
permanently adv.
pharmacy n.
physician n.
pill n.
pity n.
placement n.
portion n.
potentially adv.
precede v.
precious adj.
precise adj.
precisely adv.
predictable adj.
preference n.
presidential adj.
pride n.
primarily adv.
prior adj.
probability n.
probable adj.
proceed v.
programming n.
progressive adj.
prohibit v.
promising adj.
promotion n.
prompt v.
proportion n.
protein n.
protester n.
psychological adj.
publicity n.
publishing n.
punk n.
purely adv.
pursuit n.
puzzle n.
questionnaire n.
racial adj.
racism n.
racist adj., n.
radiation n.
rail n.
random adj.
rat n.
rating n.
reasonably adv.
rebuild v.
receiver n.
recession n.
reckon v.
recognition n.
recovery n.
recruit v., n.
referee n.
refugee n.
registration n.
regulate v.
reinforce v.
relieve v.
relieved adj.
remarkable adj.
remarkably adv.
rental n.
reporting n.
resign v.
resolution n.
restore v.
restrict v.
restriction n.
résumé n.
retail n.
retirement n.
revenue n.
revision n.
ridiculous adj.
risky adj.
rival n., adj.
rob v.
robbery n.
rocket n.
romance n.
rose n.
roughly adv.
ruin v., n.
satisfaction n.
scandal n.
scare v., n.
scenario n.
scholar n.
scholarship n.
scratch v., n.
screening n.
seeker n.
seminar n.
settler n.
severely adv.
sexy adj.
shaped adj.
shocking adj.
shore n.
shortage n.
shortly adv.
short-term adj.
sibling n.
sidewalk n.
signature n.
significance n.
skilled adj.
skull n.
slogan n.
so-called adj.
somehow adv.
sometime adv.
sophisticated adj.
spare adj.
specialize v.
specify v.
spectacular adj.
spectator n.
speculate v.
speculation n.
spice n.
spill v.
spite n.
spoil v.
spokesman n.
spokesperson n.
spokeswoman n.
sponsorship n.
stall n.
stance n.
starve v.
steadily adv.
steam n.
stimulate v.
strengthen v.
strictly adv.
stroke n.
stunning adj.
subsequent adj.
subsequently adv.
suburb n.
suffering n.
sufficient adj.
sufficiently adv.
super adj.
surgeon n.
survival n.
survivor n.
suspend v.
sustainable adj.
swallow v.
sympathetic adj.
tackle v.
tag n.
tap v., n.
technological adj.
teen n., adj
temple n.
temporarily adv.
tendency n.
tension n.
terminal n.
terms n.
terribly adv.
terrify v.
territory n.
terror n.
terrorism n.
terrorist n.
testing n.
textbook n.
theft n.
therapist n.
thesis n.
thorough adj.
thoroughly adv.
thumb n.
timing n.
tissue n.
tournament n.
trace v.
trading n.
tragedy n.
tragic adj.
trait n.
transmit v.
trap v., n.
treasure n.
tribe n.
trigger v.
trillion number
troop n.
tsunami n.
ultimate adj.
unacceptable adj.
uncertainty n.
undergo v.
undertake v.
unfold v.
unfortunate adj.
unite v.
unity n.
universal adj.
urgent adj.
usage n.
useless adj.
valid adj.
variation n.
vertical adj.
viewpoint n.
visa n.
visible adj.
voluntary adj.
voting n.
wander v.
warming n.
weekly adj.
weird adj.
welfare n.
wheat n.
whoever pron.
widespread adj.
wisdom n.
withdraw v.
wolf n.
workforce n.
workplace n.
workshop n.
worm n.
wrist n.
C1
abolish v.
abortion n.
absence n.
absent adj.
absurd adj.
abuse n., v.
academy n.
accelerate v.
acceptance n.
accessible adj.
accomplishment n.
accordingly adv.
accountability n.
accountable adj.
accumulate v.
accumulation n.
accusation n.
accused n.
acid adj.
acquisition n.
activation n.
activist n.
acute adj.
adaptation n.
adhere v.
adjacent adj.
adjustment n.
administer v.
administrative adj.
administrator n.
admission n.
adolescent n.
adoption n.
adverse adj.
advocate n., v.
aesthetic adj.
affection n.
aftermath n.
aggression n.
agricultural adj.
aide n.
alert v., n., adj.
alien adj.
align v.
alignment n.
alike adv., adj.
allegation n.
allege v.
allegedly adv.
alliance n.
allocate v.
allocation n.
allowance n.
ally n.
aluminum n.
amateur adj., n.
ambassador n.
amend v.
amendment n.
amid prep.
analogy n.
anchor n.
angel n.
anonymous adj.
apparatus n.
apparel n.
appealing adj.
appetite n.
applaud v.
applicable adj.
appoint v.
appreciation n.
arbitrary adj.
architectural adj.
archive n.
arena n.
arm v.
array n.
articulate v.
ash n.
aspiration n.
aspire v.
assassination n.
assault n., v.
assemble v.
assembly n.
assert v.
assertion n.
assurance n.
asylum n.
atrocity n.
attain v.
attendance n.
attribute v., n.
auction n.
audit n.
authentic adj.
authorize v.
auto n.
autonomy n.
autumn n.
availability n.
await v.
backdrop n.
backing n.
backup n.
bail n.
ballot n.
bankruptcy n.
banner n.
bare adj.
barrel n.
bass1 n.
bat v.
battlefield n.
bay n.
beam n.
beast n.
behalf n.
behavioral adj.
beloved adj.
bench n.
benchmark n.
beneath prep.
beneficiary n.
betray v.
beverage n.
bind v.
biography n.
bishop n.
bizarre adj.
blade n.
blast n., v.
bleed v.
blend v., n.
bless v.
blessing n.
boast v.
bonus n.
booking n.
boom n.
bounce v.
boundary n.
bow1 v., n.
breach n., v.
breakdown n.
breakthrough n.
breed v., n.
broadband n.
browser n.
brutal adj.
buddy n.
buffer n.
bulk n.
burden n.
bureaucracy n.
burial n.
burst v.
cabinet n.
calculation n.
canvas n.
capability n.
capitalism n.
capitalist adj.
cargo n.
carriage n.
carve v.
casino n.
casualty n.
catalog n.
cater v.
cattle n.
caution n.
cautious adj.
cease v.
cemetery n.
chamber n.
chaos n.
characterize v.
charm n.
charter n.
choir n.
chronic adj.
chunk n.
circulate v.
circulation n.
citizenship n.
civic adj.
civilian n., adj.
clarity n.
clash n.
classification n.
cling v.
clinical adj.
closure n.
cluster n.
coalition n.
coastal adj.
cocktail n.
cognitive adj.
coincide v.
collaborate v.
collaboration n.
collective adj.
collision n.
colonial adj.
columnist n.
combat n., v.
commence v.
commentary n.
commentator n.
commerce n.
commissioner n.
commodity n.
communist adj.
companion n.
comparable adj.
compassion n.
compel v.
compelling adj.
compensate v.
compensation n.
competence n.
competent adj.
compile v.
complement v.
complexity n.
compliance n.
complication n.
comply v.
composition n.
compromise n., v.
compute v.
conceal v.
concede v.
conceive v.
conception n.
concession n.
condemn v.
confer v.
confession n.
configuration n.
confine v.
confirmation n.
confront v.
confrontation n.
congratulate v.
congregation n.
congressional adj.
conquer v.
conscience n.
consciousness n.
consecutive adj.
consensus n.
consent n., v.
conserve v.
consistency n.
consolidate v.
constitute v.
constitution n.
constitutional adj.
constraint n.
consultation n.
contemplate v.
contempt n.
contend v.
contender n.
content2 adj.
contention n.
continually adv.
contractor n.
contradiction n.
contrary adj., n.
contributor n.
conversion n.
convict v.
conviction n.
cooperate v.
cooperative adj.
coordinate v.
coordination n.
coordinator n.
copper n.
copyright n.
correction n.
correlate v.
correlation n.
correspond v.
correspondence n.
correspondent n.
corresponding adj.
corrupt adj.
corruption n.
costly adj.
councilor n.
counseling n.
counselor n.
counter (argue against) v.
counterpart n.
countless adj.
coup n.
courtesy n.
craft v.
crawl v.
creator n.
credibility n.
credible adj.
creep v.
critique n.
crown n.
crude adj.
crush v.
crystal n.
cult n., adj.
cultivate v.
curiosity n.
custody n.
cutting n.
cynical adj.
dam n.
damaging adj.
dawn n.
debris n.
debut n.
decision-making n.
decisive adj.
declaration n.
dedicated adj.
dedication n.
deed n.
deem v.
default n.
defect n.
defensive adj.
deficiency n.
deficit n.
defy v.
delegate n.
delegation n.
delicate adj.
demon n.
denial n.
denounce v.
dense adj.
density n.
dependence n.
depict v.
deploy v.
deployment n.
deprive v.
deputy n.
descend v.
descent n.
designate v.
desirable adj.
desktop n.
destructive adj.
detain v.
detection n.
detention n.
deteriorate v
devastate v.
devil n.
devise v.
diagnose v.
diagnosis n.
dictate v.
dictator n.
differentiate v.
dignity n.
dilemma n.
dimension n.
diminish v.
dip v.
diplomat n.
diplomatic n.
directory n.
disastrous adj.
discard v.
discharge v.
disclose v.
disclosure n.
discourse n.
discretion n.
discrimination n.
dismissal n.
displace v.
disposal n.
dispose v.
dispute n., v.
disrupt v.
disruption n.
dissolve v.
distinction n.
distinctive adj.
distort v.
distress n., v.
disturbing adj.
divert v.
divine adj.
doctrine n.
documentation n.
domain n.
dominance n.
donor n.
dose n.
drain v.
drift v.
driving adj.
drown v.
dual adj.
dub v.
dumb adj.
duo n.
dynamic n.
earnings n.
ease n., v.
echo v., n.
ecological adj.
educator n.
effectiveness n.
efficiency n.
ego n.
elaborate adj.
electoral adj.
elevate v.
eligible adj.
elite n.
embark v.
embarrassment n.
embassy n.
embed v.
embody v.
emergence n.
empirical adj.
empower v.
enact v.
encompass v.
encouragement n.
encouraging adj.
endeavor n.
endless adj.
endorse v.
endorsement n.
endure v.
enforce v.
enforcement n.
engagement n.
engaging adj.
enrich v.
enroll v.
ensue v.
enterprise n.
enthusiast n.
entitle v.
entity n.
epidemic n.
equality n.
equation n.
erect v.
escalate v.
essence n.
establishment n.
eternal adj.
evacuate v.
evoke v.
evolutionary adj.
exaggerate v.
excellence n.
exceptional adj.
excess n., adj.
exclusion n.
exclusive adj.
exclusively adv.
execute v.
execution n.
exert v.
exile n.
expenditure n.
experimental adj.
expire v.
explicit adj.
explicitly adv.
exploitation n.
explosive adj., n.
extract v.
extremist n.
facilitate v.
faction n.
fade v.
fairness n.
fatal adj.
fate n.
favorable adj.
feat n.
felony n.
feminist adj., n.
fiber n.
fierce adj.
filmmaker n.
filter n., v.
fine n., v.
firearm n.
fiscal adj.
fit n.
flaw n.
flawed adj.
flee v.
fleet n.
flesh n.
flexibility n.
flourish v.
fluid n.
footage n.
foreigner n.
forge v.
formula n.
formulate v.
forth adv.
forthcoming adj.
foster v.
fragile adj.
franchise n.
frankly adv.
freshman n.
frustrated adj.
frustrating adj.
frustration n.
functional adj.
fundraising n.
funeral n.
gambling n.
gathering n.
gaze n., v.
gear n.
generic adj.
genocide n.
gig n.
glance n., v.
glimpse n.
glorious adj.
glory n.
governance n.
grace n.
grasp v.
grave (for dead person) n.
grave (serious) adj.
gravity n.
grid n.
grief n.
grin v., n.
grind v.
grip n., v.
gross adj.
guerrilla n.
guidance n.
guilt n.
gut n.
hail v.
halfway adv.
halt v., n.
handful n.
handling n.
handy adj.
harassment n.
hardware n.
harmony n.
harsh adj.
harvest n., v.
hatred n.
haunt v.
hazard n.
heighten v.
heritage n.
hierarchy n.
high-profile adj.
hint n., v.
homeland n.
hook v.
hopeful adj.
horizon n.
horn n.
hostage n.
hostile adj.
hostility n.
humanitarian adj.
humanity n.
humble adj.
hydrogen n.
identification n.
ideological adj.
ideology n.
idiot n.
ignorance n.
imagery n.
immense adj.
imminent adj.
implementation n.
imprison v.
inability n.
inadequate adj.
inappropriate adj.
incarcerate v.
incarceration n.
incidence n.
inclined adj.
inclusion n.
incur v.
indicator n.
indictment n.
indigenous adj.
induce v.
indulge v.
inequality n.
infamous adj.
infant n.
infect v.
inflict v.
influential adj.
inherent adj.
inhibit v.
initiate v.
inject v.
injection n.
injustice n.
inmate n.
inquire v.
insertion n.
insider n.
inspect v.
inspection n.
inspiration n.
instinct n.
institutional adj.
instruct v.
instrumental adj.
insufficient adj.
insult n., v.
intact adj.
intake n.
integral adj.
integrated adj.
integration n.
integrity n.
intellectual n.
intensify v.
intensity n.
intensive adj.
intent n.
interactive adj.
interface n.
interfere v.
interference n.
interim adj.
interior adj., n.
intermediate adj.
intersection n.
intervene v.
intervention n.
intimate adj.
intriguing adj.
inventory n.
investigator n.
invisible adj.
invoke v.
involvement n.
ironic adj.
ironically adv.
irony n.
irrelevant adj.
isolation n.
judicial adj.
jurisdiction n.
just adj.
justification n.
keen adj.
kidnap v.
kidney n.
kingdom n.
landlord n.
landmark n.
lap n.
large-scale adj.
laser n.
latter adj., n.
lawmaker n.
lawn n.
lawsuit n.
layout n.
leak v., n.
leap v., n.
legacy n.
legendary adj.
legislation n.
legislative adj.
legislature n.
legitimate adj.
lengthy adj.
lesbian adj.
lesser adj.
lethal adj.
liable adj.
liberal adj., n.
liberation n.
liberty n.
lifelong adj.
likelihood n.
limb n.
linear adj.
lineup n.
linger v.
listing n.
liter n.
literacy n.
liver n.
lobby n., v.
log n., v.
logic n.
long-standing adj.
longtime adj.
loom v.
loop n.
loyalty n.
machinery n.
magical adj.
magnetic adj.
magnificent adj.
magnitude n.
mainland n.
mainstream n., adj.
maintenance n.
mandate n.
mandatory adj.
manifest v.
manipulate v.
manipulation n.
manuscript n.
march n., v.
marginal adj.
marine adj.
marketplace n.
mask n.
massacre n.
mathematical adj.
mature adj., v.
maximize v.
meaningful adj.
meantime n.
medieval adj.
meditation n.
melody n.
memo n.
memoir n.
memorial n.
mentor n.
merchant n.
mercy n.
mere adj.
merely adv.
merge v.
merger n.
merit n.
methodology n.
midst n.
migration n.
militant n., adj.
militia n.
mill n.
minimal adj.
minimize v.
mining n.
ministry n.
minute2 adj.
miracle n.
misery n.
misleading adj.
missile n.
mob n.
mobile adj.
mobility n.
mobilize v.
moderate adj.
modification n.
module n.
momentum n.
monk n.
monopoly n.
morality n.
motive n.
municipal adj.
mutual adj.
namely adv.
nationwide adj.
naval adj.
neglect v.
neighboring adj.
nest n.
net adj.
newsletter n.
niche n.
noble adj.
nod v.
nominate v.
nomination n.
nominee n.
nonetheless adv.
nonprofit adj.
nonsense n.
noon n.
notable adj.
notably adv.
notify v.
notorious adj.
novel adj.
nursery n.
objection n.
oblige v.
obsess v.
obsession n.
occasional adj.
occurrence n.
odds n.
offering n.
offspring n.
operational adj.
opt v.
optical adj.
optimism n.
oral adj.
organizational adj.
orientation n.
originate v.
outbreak n.
outing n.
outlet n.
outlook n.
outrage n., v.
outsider n.
overlook v.
overly adv.
oversee v.
overturn v.
overwhelm v.
overwhelming adj.
pad n.
parameter n.
parental adj.
parliament n.
partial adj.
partially adv.
passing n.
passive adj.
pastor n.
patent n.
pathway n.
patrol n., v.
patron n.
peak n.
peasant n.
peculiar adj.
pension1 n.
persist v.
persistent adj.
personnel n.
petition n.
philosopher n.
philosophical adj.
pioneer n., v.
pipeline n.
pirate n.
pit n.
plea n.
plead v.
pledge v., n.
plug v., n.
plunge v.
pole n.
poll n.
pond n.
pop v.
portfolio n.
portray v.
postpone v.
postwar adj.
practitioner n.
preach v.
precedent n.
precision n.
predator n.
predecessor n.
predominantly adv.
pregnancy n.
prejudice n.
preliminary adj.
premier n.
premise n.
premium n.
prescribe v.
prescription n.
presently adv.
preservation n.
preside v.
presidency n.
prestigious adj.
presumably adv.
presume v.
prevail v.
prevalence n.
prevention n.
prey n.
privatization n.
privilege n.
probe n., v.
problematic adj.
proceeding n.
proceeds n.
processing n.
processor n.
proclaim v.
productive adj.
productivity n.
profitable adj.
profound adj.
projection n.
prominent adj.
pronounced adj.
propaganda n.
proposition n.
prosecute v.
prosecution n.
prosecutor n.
prospective adj.
prosperity n.
protective adj.
protocol n.
province n.
provincial adj.
provision n.
provoke v.
psychiatric adj.
pulse n.
pump v., n.
punch n., v.
query n.
quest n.
quota n.
radar n.
radical adj.
rage n.
raid n., v.
rally n., v.
ranking n.
rape n., v.
ratio n.
rational adj.
ray n.
readily adv.
realization n.
realm n.
rear adj., n.
reasoning n.
reassure v.
rebel n.
rebellion n.
recipient n.
reconstruction n.
recount1 v.
recruitment n.
referendum n.
reflection n.
reform n., v.
refuge n.
refusal n.
regain v.
regardless adv.
regime n.
regulator n.
regulatory adj.
rehabilitation n.
reign n., v.
rejection n.
relevance n.
reliability n.
reluctant adj.
remainder n.
remains n.
remedy n.
reminder n.
removal n.
render v.
renew v.
renowned adj.
replacement n.
reportedly adv.
representation n.
reproduce v.
reproduction n.
republic n.
resemble v.
reside v.
residence n.
residential adj.
residue n.
resignation n.
resistance n.
respective adj.
respectively adv.
restoration n.
restraint n.
resume v.
retreat n., v.
retrieve v.
revelation n.
revenge n.
reverse v., n., adj.
revival n.
revive v.
revolutionary adj.
rhetoric n.
rifle n.
riot n.
rip v.
ritual n.
robust adj.
rock v.
rod n.
rookie n.
roster n.
rotate v.
rotation n.
ruling n.
rumor n.
sacred adj.
sacrifice n., v.
saint n.
sake n.
sanction n.
say n.
scattered adj.
scope n.
screw v., n.
scrutiny n.
seal v., n.
secondly adv.
secular adj.
seemingly adv.
segment n.
seize v.
seldom adv.
selective adj.
sensation n.
sensitivity n.
sentiment n.
separation n.
serial adj.
settlement n.
setup n.
sexuality n.
shareholder n.
shatter v.
shed v.
sheer adj.
shipping n.
shoot n.
shrink v.
shrug v.
sigh v., n.
simulate v.
simulation n.
simultaneously adv.
sin n.
situated adj.
skeptical adj.
sketch n.
skip v.
slam v.
slap v.
slash v.
slavery n.
slot n.
smash v.
snap v.
soak v.
soar v.
socialist adj.
sole adj.
solely adv.
solidarity n.
solo adj., n.
sophomore n.
sound adj.
sovereignty n.
spam n.
span v., n.
spare v.
spark v.
specialized adj.
specification n.
specimen n.
spectacle n.
spectrum n.
spell n.
sphere n.
spin v., n.
spine n.
spotlight n.
spouse n.
spy n., v.
squad n.
squeeze v.
stab v.
stability n.
stabilize v.
stake n.
standing adj.
stark adj.
statistical adj.
steer v.
stem n., v.
stereotype n.
stimulus n.
stir v.
storage n.
straightforward adj.
strain n.
strand n.
strategic adj.
striking adj.
strip (long narrow piece) n.
strip (remove clothes/a layer) v.
strive v.
structural adj.
stumble v.
stun v.
submission n.
subscriber n.
subscription n.
subsidy n.
substantial adj.
substantially adv.
substitute n., v.
substitution n.
subtle adj.
suburban adj.
succession n.
successive adj.
successor n.
suck v.
sue v.
suicide n.
suite n.
summit n.
superb adj.
superintendent n.
superior adj.
supervise v.
supervision n.
supervisor n.
supplement n., v.
supportive adj.
supposedly adv.
suppress v.
supreme adj.
surge n., v.
surgical adj.
surplus n.
surrender v.
surveillance n.
suspension n.
suspicion n.
suspicious adj.
sustain v.
swing v., n.
sword n.
symbolic adj.
syndrome n.
synthesis n.
systematic adj.
tackle n.
tactic n.
tactical adj.
taxpayer n.
tempt v.
tenant n.
tender adj.
tenure n.
terminal adj.
terminate v.
terrain n.
terrific adj.
testify v.
testimony n.
texture n.
thankfully adv.
theatrical adj.
theology n.
theoretical adj.
thereafter adv.
thereby adv.
thoughtful adj.
thought-provoking adj.
thread n.
threshold n.
thrilled adj.
thrive v.
tide n.
tighten v.
timber n.
timely adj.
tobacco n.
tolerance n.
tolerate v.
toll n.
top v.
torture n., v.
toss v.
total v.
toxic adj.
trace n.
trademark n.
trail n., v.
trailer n.
transaction n.
transcript n.
transformation n.
transit n.
transmission n.
transparency n.
transparent adj.
trauma n.
treaty n.
tremendous adj.
tribal adj.
tribute n.
trigger n.
trio n.
triumph n.
trophy n.
troubled adj.
trustee n.
tuition n.
tumor n.
turnout n.
turnover n.
twist v., n.
unconstitutional adj.
undergraduate n.
underlying adj.
undermine v.
undoubtedly adv.
unify v.
unprecedented adj.
unveil v.
upcoming adj.
upgrade v., n.
uphold v.
utility n.
utilize v.
utterly adv.
vacuum n.
vague adj.
validity n.
vanish v.
variable n., adj.
varied adj.
vein n.
venture n., v.
verbal adj.
verdict n.
verify v.
verse n.
versus conj.
vessel n.
veteran n.
viable adj.
vibrant adj.
vice n.
vicious adj.
violate v.
violation n.
virtue n.
vocal adj.
vow v.
vulnerability n.
vulnerable adj.
ward n.
warehouse n.
warfare n.
warrant n., v.
warrior n.
weaken v.
weave v.
weed n.
well n.
well-being n.
whatsoever adv.
whereby adv.
whip v.
wholly adv.
widen v.
widow n.
width n.
willingness n.
wipe v.
wit n.
withdrawal n.
workout n.
worship n., v.
worthwhile adj.
worthy adj.
yell v.
yield n., v.
"""
tokens = 