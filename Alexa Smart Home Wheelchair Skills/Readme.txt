Charlotte IoT: Alexa Smart Home Wheelchair Skills
Tech Lead: Jeremy Proffitt

This skills kit allows you to add up to 4 different Alexa Smart Home Items, each one is programmable between basic on/off and on/off with percent control/adjustment.  We hope to expand this to include colored lights, locks and thermostats in the future and some of that ground work is already in the code.

On the hardware side, we start with a Particle.IO running the particle-alexa.ino code.  This code by default exposes 4 end points for 4 different pins.  You MUST ensure that the pins you choose can be controlled via PWM.

To set up Alexa:  (NOTE: follow 2nd link below for setting up oauth)

  Use Python 3.6 and the Alexa.py source for the python source in the Lamda expression.

  Steps to Create a Smart Home Skill - Amazon Apps & Services Developer Portal  
  https://developer.amazon.com/public/solutions/alexa/alexa-skills-kit/docs/steps-to-create-a-smart-home-skill  
	
When you are asked for the oAuth credentials, follow these steps

  HOWTO Add OAuth to your Alexa Smart Home Skill in 10 Minutes
  https://www.whizzy.org/2016/12/howto-add-oauth-to-your-alexa-smart-home-skill-in-10-minutes/

Both of these web pages are in PDF format in the docs folder in the repository in case those sites go offline.

When following the alexa tutorial, the following changes must be made.  

