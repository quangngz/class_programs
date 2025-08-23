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
- Unique username
- first name
- last name
- unique email adress
- unique phone number
- unique social media account of the following type: {Facebook, Instagram, X, Bluesky, Xiaohongshu, or tiktok} (only 1 type - list is fixed).
- number of warnings: if equal 3, the user is terminated. Everyone starts out at 0. 
- User's that are terminated cannot join again using the same email address, phone number, or social media. 
- User have a reputation score (decimal numbers), this is calculated by the platform. 

- each usser can have a maximum of 500 connections 


