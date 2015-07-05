Here's a few quick tips for checkins to naclports.
  * If you haven't been through the HowTo\_Checkout page already, please do so.
  * Please use '`git cl upload`' from depot\_tools to send your change out for review to native-client-reviews. Watch review traffic on the list if you are not familiar with local customs for code reviews. You will need to set up an [App-Specific Password](https://www.google.com/accounts/b/0/IssuedAuthSubTokens) in order to use the code review tool.
  * If you are not a Google employee you need to submit a completed Contributor License Agreement as described on the [Chromium "Contributing Code" page](http://www.chromium.org/developers/contributing-code).

Once you have an LGTM for your change list, if you are a member of the naclports project, then follow these steps:
  * Follow [these](http://www.chromium.org/developers/how-tos/get-the-code#TOC-Git-credentials-setup-for-committers-.netrc-file-) instructions to setup your .netrc with credentials for commiting.
  * '`git cl land`' is the command to use to commit your change.


If you not a member of the naclports project, ask one of your reviewers to finish submitting your CL. Once you have submitted a few CLs and demonstrated you know how to stay out of trouble then you can ask one of the project administrators to add you as a naclports project member.