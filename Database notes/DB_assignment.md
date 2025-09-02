## Entities

### Hub
- Owned by a personality or a organisation. 
- Have their own profile photo. 
- Unique username starting with @
- Description
- email adress, 
- verified status
- type(s) of the following:
    -   {Celebrity, Organisation, Product, Internet influencer, News agency}, and more if we wish to add later.
    - A Hub can be multiple types. 

- Hub have a timeline of POSTS (another entity)
- Hub may have any number of moderators. (Another entity)

### Posts
- Each Hub should have atleast 1 post. No co-creation is allowed (no 2 hub owns the same Posts). 
- The Posts have a unique ID (using UUID format- "cadc6b45-
c296-4cb9-9470-b30aaf4a3cb3”)
- Has text
- date and timestamp
- preview (optional) with type (png, jpg, or gif)
- A post can also link to outside URLs of youtube, Instagram, ... or it can link to one or more post through the UUID. 

### Users
- Unique username (Primary Key)
- first name
- last name
- unique email adress
- unique phone number
- unique social media account of the following type: {Facebook, Instagram, X, Bluesky, Xiaohongshu, or tiktok} (only 1 type - list is fixed).
- number of warnings: if equal 3, the user is terminated. Everyone starts out at 0. 
- User's that are terminated cannot join again using the same email address, phone number, or social media. 
- User have a reputation score (decimal numbers), this is calculated by the platform. 
- each user can have a maximum of 500 connections 
- Connetion has start date and 2 descriptions, one from each user, a line like: "met X at a party"
- If a connection is ended by one of the users, it should no longer be recorded in the system. All connections are bi-directional: a connection is
only established when one user initiates it and the other user confirms it by adding their own description; otherwise, it is not recorded
- User can create atmost once on each posts. 
- User can tag up to 10 other users in each posts. 


### Comment (Weak entity, depends on both User and Post)
- Unique number
- TExt
- TIme / date it was made

### Moderator 
- User can be a moderator for a fixed amount of time. 
- Assignment code (starting time - ending time)
- Past assignment (multi value attributes). 
- Hubs in charge (list of all hubs the user is a moderator in). 

### Report entity (Relationship between user and hub)
- It has to be a post inside the hub that the moderator is in charge. 
- Time stamp
- Decision:  Verified Human Content, Verified GenAI Content, Potential Bias, Fake Content, Clickbait, AI Slop, or Uncertain Status
- Comment

### Report Comment (Relationship between user and hub)
-  Comment can have any number of Reports, with each of their timestamps/moderator/comment/
decision tracked. 
- report decisions on Comments can only be one of: (Wholesome Feedback, Informative Content, Rule Violation, or Neutral Content). 
- Moderators cannot use AIAgents to check Comments. 
- If the comment has been determined to violate rules, the user who authored it will have their warning count increased by one
### AI agent (Weak entity to moderator)
- At most 1 AI agent per mod. 
- which has a name 
- corresponding source code
- the same AIAgent may be used by multiple moderators.
- if a report has been generated with the help of this AIAgent, it should be tracked for transparency



## Business Goal
1. How many moderators have been assigned to 2 or more different hubs (e.g., both BTS and BlackPink)?
2. How many times has the user BreakingNews1234 been warned?
3. Among all hubs that have at least a post containing an external link to a URL in the “twitch.tv” domain,
which hub has the highest total number of posts’ reports where the moderator(s)’ decision was
“Clickbait”?
4. Which moderators who are connections to EthicalUser123 did not use any AI agents?
5. (For auditing purposes) Which unethical moderators have reviewed their own comments?
6. How many posts are written by hubs that are news agencies, with the text containing ‘breaking news’?
INFO20003 S2 2025 | ASSIGNMENT 1 – NEWSPAPER.NET | VERSION: v1.0 | page 4
7. How many times did the users Sandy, Farzaneh, and Lillian get tagged in comments, in total?
8. Which hubs have had their posts moderated using at least 3 different AI agents?
9. (For debugging purposes) What is the source code of the AI agent(s) used in moderating post(s) for the
hub “MrFeast” on 22 December 2025, 10:15 to 10:20 am (inclusive), where MrFeast’s posts have links to
posts by AshtonKutcher?
10. (For legal purposes) Which users with reputation less than –50.0 have created comments on posts with
higher ratios of ‘Fake Content’ reports (than any other decision).
11. How many users have more than 400 connections with other users?
12. Which hubs have posted at least 3 posts that were linked to another post?