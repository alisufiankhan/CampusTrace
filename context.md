PROJECT: CampusTrace
TYPE: C++ OOP Console Application
PURPOSE: Lost and Found Management System for 
university campuses

CURRENT STATUS: All 14 header files are complete 
and pushed to GitHub. Now implementing .cpp files 
for Ali Sufian's classes only.

TEAM:
- Ali Sufian (leader) — Person, Student, Admin, 
  SearchLog, Report, main.cpp — IMPLEMENTING NOW
- Amina Shafique — Item, ElectronicItem, 
  DocumentItem, PersonalItem — will implement 
  separately
- Umama Khurram — Transaction, Claim, Handover, 
  Reward, FileManager, MatchEngine — will 
  implement separately

LANGUAGE: C++11 or higher
INTERFACE: Console / Terminal
COMPILER: g++
VERSION CONTROL: GitHub repo: CampusTrace

FOLDER STRUCTURE:
CampusTrace/
├── include/    (all .h header files — DONE)
├── src/        (all .cpp files — IN PROGRESS)
├── data/       (text files for FileManager)
└── main.cpp

════════════════════════════════════════
FULL SYSTEM ARCHITECTURE
════════════════════════════════════════

CLASS HIERARCHY:
3 inheritance trees, all hierarchical inheritance:

TREE 1 — USER:
Person (base)
  -> Student
  -> Admin

TREE 2 — ITEM (Amina's):
Item (base)
  -> ElectronicItem
  -> DocumentItem
  -> PersonalItem

TREE 3 — TRANSACTION (Umama's):
Transaction (base)
  -> Claim
  -> Handover

STANDALONE:
Reward (Umama), SearchLog (Ali), Report (Ali), 
FileManager (Umama), MatchEngine (Umama)

════════════════════════════════════════
ALL 14 CLASSES — FULL REFERENCE
════════════════════════════════════════

Person (Base — ALI):
  private: name(string), ID(string), 
           contact(string), password(string)
  public: login(), getInfo()
  getters: getName(), getID(), getContact(), 
           getPassword()

Student (-> Person — ALI):
  private: rollNumber(string), dept(string), 
           rejections(int), isFlagged(bool)
  public: claimItem(), viewStatus(), 
          incrementRejections()
  getters: getRollNumber(), getDept(), 
           getRejections(), getIsFlagged()

Admin (-> Person — ALI):
  private: adminID(string), shift(string)
  public: addItem(), approveClaim(), 
          processHandover(), rejectClaim()
  getters: getAdminID(), getShift()

Item (Base — AMINA):
  private: itemID(string), desc(string), 
           dateFound(string), location(string), 
           status(string)
  public: virtual getDetails(), updateStatus(), 
          isExpired()
  getters: getItemID(), getDesc(), 
           getDateFound(), getLocation(), 
           getStatus()

ElectronicItem (-> Item — AMINA):
  private: brand(string), color(string), 
           serialNumber(string)
  public: getDetails() override
  getters: getBrand(), getColor(), 
           getSerialNumber()

DocumentItem (-> Item — AMINA):
  private: docType(string), issuedBy(string)
  public: getDetails() override
  getters: getDocType(), getIssuedBy()

PersonalItem (-> Item — AMINA):
  private: color(string), size(string), 
           material(string)
  public: getDetails() override
  getters: getColor(), getSize(), getMaterial()

Transaction (Base — UMAMA):
  private: transactionID(string), date(string), 
           person(Person*)
  public: virtual processTransaction()
  getters: getTransactionID(), getDate(), 
           getPerson()

Claim (-> Transaction — UMAMA):
  private: claimID(string), proof(string), 
           status(string), item(Item*)
  public: submitClaim(), validateClaim(), 
          processTransaction() override,
          setDisputed()
  getters: getClaimID(), getProof(), 
           getClaimStatus(), getItem()

Handover (-> Transaction — UMAMA):
  private: handoverID(string), condition(string),
           witness(string)
  public: confirmHandover(), generateReceipt(), 
          processTransaction() override
  getters: getHandoverID(), getCondition(), 
           getWitness()

Reward (Standalone — UMAMA):
  private: rewardID(string), offeredBy(string), 
           desc(string), status(string)
  public: offerReward(), cancelReward(), 
          getStatus()
  getters: getRewardID(), getOfferedBy(), 
           getRewardDesc(), getRewardStatus()

SearchLog (Standalone — ALI):
  private: logID(string), keyword(string), 
           timestamp(string), studentID(string)
  public: logSearch(), getHistory()
  getters: getLogID(), getKeyword(), 
           getTimestamp(), getStudentID()

Report (Standalone — ALI):
  private: reportID(string), generatedBy(string),
           dateRange(string), 
           items(vector<Item*>)
  public: generateReport(), countByStatus(), 
          listExpired()
  getters: getReportID(), getGeneratedBy(), 
           getDateRange()

FileManager (Standalone — UMAMA):
  private: itemsFile(string), usersFile(string), 
           claimsFile(string)
  public: saveItems(), loadItems(), 
          saveClaims(), loadClaims()

MatchEngine (Standalone — UMAMA):
  public: searchByKeyword(string keyword, 
          vector<Item*> allItems)

════════════════════════════════════════
MVP FEATURES
════════════════════════════════════════
M1  - Admin login + item registration
M2  - Student login + item search
M3  - Formal claim submission
M4  - Admin claim review (approve/reject)
M5  - Item status lifecycle
M6  - Handover processing
M7  - Claim dispute handling
M8  - File handling (data persistence)
M9  - 30-day item expiry
M10 - Student trust flag

════════════════════════════════════════
OOP RULES — NEVER VIOLATE
════════════════════════════════════════
- Every attribute is private
- No public attributes ever
- getDetails() is virtual in Item
- processTransaction() is virtual in Transaction
- All derived classes use override keyword
- Items stored as vector<Item*> for polymorphism
- Use unique_ptr where possible
- Status only changes through controlled methods
- #ifndef guard in every header file

════════════════════════════════════════
ITEM STATUS VALUES
════════════════════════════════════════
Found / UnderReview / Claimed / 
Returned / Disputed / Expired

════════════════════════════════════════
IMPORTANT INTEGRATION NOTES
════════════════════════════════════════
- Transaction holds Person* — receives from 
  Ali's code, never creates
- Claim holds Item* — receives from Amina's 
  code, never creates
- FileManager reads and writes all three layers
- main.cpp (Ali) wires everything together
- All function names are final and locked
- Do not rename anything

════════════════════════════════════════
PASSWORDS AND ACCOUNTS
════════════════════════════════════════
- Stored as plain string in Person class
- Loaded from file at startup via FileManager
- No self-registration
- Admin creates all accounts