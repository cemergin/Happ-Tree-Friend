
# Happy Tree Friend
Exploring ways to augment human-plant interactions to create a feeling of companionship between houseplants and residents that live alone. 

## Summary
Keywords: Internet of Things, Field Research, Concept Development, Rapid Prototyping, Interaction Design

Happy Tree Friend, is an Internet of Things project that I personally designed and developed for “Designing for the Internet of Things” class I’ve attended during my Spring 2019 semester at Carnegie Mellon University. 

The concept of creating a feeling of companionship between houseplants and residents that live alone was developed after the field research I’ve conducted. For the initial prototype, I’ve only looked at “call-to-action” interactions that invited the resident to physically interact with the houseplant using four sensors placed on the plant itself. By checking the temperature, luminance and soil moisture around the plant, I was able to notify the resident when they are physically around the plant. For severe conditions like freezing temperatures, the plant is currently capable of reaching out to the resident digitally. 

Intention
When I typed "epidemic of" on a Google search bar, one of the first suggestion to appear was the word "loneliness". For research purposes only, I clicked on that suggestion and watched the search engine locate about 2,640,000 results for me, under 0.5 seconds. The first dozen results that appeared on my screen were fairly recent. They consisted of links directing me to articles published by The Atlantic, The Economist,  The New York Times and The Washington Post published in the last couple of years. 

Glancing at the mentioned texts, it seems to me that the technology of today; which is capable of connecting millions of electronic gadgets to each other, isn't quite able to provide us with a feeling of connection and companionship. The train of thoughts that started with me typing in "epidemic of" to a search bar went into hyperspeed as I was conducting my field study at a close friends house. He is an international student and lives alone, just like me.

During the interview, we went through a lot of the objects that were located in the house: the Google Home Mini, the smart plugs, the microwave, the sofa, the radiator knob, the steam cooker... Interestingly, all his favorite gizmos had the same set of features! They offered efficiency and productivity. They were totally replaceable if they broke. On the other hand, none of these items offered a connection on an emotional level. He only mentioned one or two objects that can unfold sentiments or memories. 

I was trying to find the reason why it was so hard for him to locate a personally valuable object in the house and then it hit me. As international students moving into a distant country, we can only bring our most necessary belongings with us. We only buy the most necessary gadgets, to keep the budget afloat. He couldn't name emotional objects because they weren't there in the first place. Candidates for the job are probably neatly packed in a cardboard box, sitting in an old storage room miles away. So, we don't have any objects that connect us to the house and we need to build our homes from scratch. 

Coming back to the interview, our co-designed answer to this emotional need arising from our house full of dispassionate objects was cohabiting the space with another living creature; a dog, a cat, a tortoise or a plant. Combining all these ideas and reminding myself of the recommendation that my mother made about turning my house into a home, I decided to direct my attention to plants. 

My intention was to investigate ways of enchanting our interactions with houseplants. 

The goal of this project is to investigate the ways of creating meaningful interactions between house plants and residents, to somehow combat the spread of feeling lonely and the rising need for connection today.  

## Process

### Understand

On my way back from the aforementioned interview, I remembered another object that I held really dear to myself years ago; the Tamagotchi. I recalled the days I walked around the neighbourhood with a virtual pet and how it felt. The interactions I remembered were limited but pleasing. You took care of your virtual pet and tried to keep it happy by feeding it and playing simple games with it. 

I wanted to replicate a similar feeling with my enchanted house plant. So, to refresh my memories on how Tamagotchis work, I bought one from Amazon and walked around with a virtual pet in my pocket. I studied the ways you interacted with it and how the pet asked for attention from the player. 

What I found out is that there are 6 different actions you can take to interact with a Tamagotchi pet which includes feeding it, cleaning after it, scolding it or playing a simple number guessing game with it. The main actions necessary to keep it happy is feeding and playing the game with it. I thought that these simple but effective interactions can be the guiding examples for this project. 

On the other hand, I found out the hard way that these toys were actually a little intrusive back in the day. The virtual pet asks for your attention at random intervals by playing a very annoying beep sound until you do what it says. This happened to me during class a couple times and I got some weird looks as I was attending my virtual pet. I concluded that my project should communicate with the players in a more ambient display style rather than demanding immediate attention if it's not needed. 

In addition to my Tamagotchi experiment, I also compiled a list of articles and papers on human-plant interaction and went through some of them to understand what has been done in the area. You can find the articles I came across at "Further Readings" listed down below. 

### Define

Meanwhile, I also acquired a small house plant to observe. A lovely little weeping fig plant, ficus benjamina. I used the experience I got from playing with a Tamagotchi for a couple days to come up with interactions for my enchanted plant. Most of the actions available for the toy was focused on taking care of the virtual pet. There was only one action that helped you to play a game with it. Therefore, I focused on the needs of my plant at this stage. 

I isolated 3 key aspects to look into: Soil moisture, Room Temperature, Room illuminance. The idea was to monitor these conditions and present the residents with actionable reminders. I also concluded that unlike the Tamagotchi, the reminders should be simple, noticeable and timely. Because it doesn't make sense to notify the residents excessively or when they aren't at around. So the problem boiled down to getting the information about the three aspects mentioned above and turning them into non-intrusive notifications for the residents. 

### Generate

Considering the tools and components that were readily available I came up with the schematic below. It uses 3 sensors to monitor the state of the plant and another one to monitor the movement around the plant. The goal is to flash the RGB Neopixel when one of the sensors detects unhealthy conditions for the plant, but only when someone is around.  

For each unhealthy condition; namely low soil moisture, unfit room temperature or not enough light, I dedicated one unique colour: RED for temperature alert, MAGENTA for soil moisture and ORANGE for low luminescence. I used the info card that came with the plant to set the necessary numbers for these alerts.

## Demo

After hours of building and coding, I was able to get the prototype to work as planned. The video that welcomes you to this documentation page demonstrates how the system works. As you can see, when I remove the moisture sensor from soil; forcing the sensor to detect low-moisture, and wave my hand in front of the PIR sensor the LED flashes. 

When I wave my hand for the second time, the LED doesn't immediately flash because the system has to wait for a while before flashing again. For demonstration purposes, I set that the amount of wait time to be pretty low but practically it should at least be 5 minutes. 

## Code

The code above demonstrates the looping behavior of the set-up. It first checks all the plant sensors and changes the necessary variables that correspond to the readings. After that, it looks for a signal from the PIR sensor for movement which turns the boolean pirState true if there's movement around the plant. 

To avoid bombarding the residents with colorful notifications as they move around their homes, I added a timer functionality to the code. The Neopixel only flashes when a certain time has passed and the PIR senses movement. If both conditions are met, the code checks the results of the readings and sets the booleans; tempAlert, soilAlert and brightnessAlert, to true if needed. Then the code checks if any of these set to true and flashes the colors that correspond to each warning.  

## Connect

To display that the system can be connected to the internet for added features, I created an IFTTT warning for the room temperature reading. This way if the system gets a temperature reading lower than 55 degrees, the user gets a down-to-earth e-mail from their plant asking them to move it somewhere else. You can view the e-mail I got while trying out this feature. 

Final Components List:


1x Particle Argon

1x PIR Motion Sensor

1x Soil Moisture Sensor

1x TMP36 Temperature Sensor

1x Photoresistor

1x Red LED

1x RGB Smart Neopixel

1x 10nF Ceramic Capacitor

1x 1okΩ resistor

1x 1kΩ resistor

# Next Steps
Due to time constraints, I was not able to go through multiple iterations for this project. I stopped after creating the first working prototype. If there were more time, I would create different versions experimenting with different interaction techniques using haptic feedback, sound, touch sensors. 

After creating variations and producing better-looking prototypes, the next steps would involve distributing different versions to lonely volunteers and conduct a user study on the effects of this new human-plant interaction. With more iterations and research, a better user experience can be crafted and my dream of creating a Tamagotchi house plant would be better realized.

Additionally, if the research shows that the prototypes can create value for the users, the findings can be used to start a Kickstarter project. Alternatively, the findings and the designs can be shared with the open-source and DIY communities to help people investigate more interesting human-plant interactions in their own projects. 

Lastly, I found out that ficus benjamina is not the easiest house plant to look after. They are originally found in tropical regions of the world and require a lot of attention to stay in shape. If I were to pursue this project further, I would test out different indoor houseplants to create the list of species that are more suitable for the job and tailor the design for those specific species. 

# Reflection
As stated above, there's a lot that can be done with this project. Usability Tests, Kickstarter pages, Open-Source community articles, design for a Most Viable Product... Unfortunately, I didn't have the time and energy to get the project to these stages. I'm still pretty happy with where I ended up. I think that it does a good job as a proof-of-concept prototype. 

I'm looking forward to designing and prototyping new enchanted objects. 

References and Acknowledgements
Main Source of Wisdom
https://diotlabs.daraghbyrne.me/

# Further Reading
Ayumi Kawakami, Koji Tsukada, Keisuke Kambara, and Itiro Siio. 2010. PotPet: pet-like flowerpot robot. In Proceedings of the fifth international conference on Tangible, embedded, and embodied interaction (TEI '11). ACM, New York, NY, USA, 263-264. DOI: http://dx.doi.org/10.1145/1935701.1935755

Bashkim Isai and Stephen Viller. 2010. Meet Eater: affectionate computing, social networks and human-plant interaction. In Proceedings of the 22nd Conference of the Computer-Human Interaction Special Interest Group of Australia on Computer-Human Interaction (OZCHI '10). ACM, New York, NY, USA, 414-415. DOI: http://dx.doi.org/10.1145/1952222.1952322

James Serpell. (1991). Beneficial Effects of Pet Ownership on Some Aspects of Human Health and Behaviour. Journal of the Royal Society of Medicine. 84. 717-720. 10.1177/014107689108401208. 

Leonardo Angelini, Stefania Caparrotta, Omar Abou Khaled, and Elena Mugellini. 2016. EmotiPlant: Human-Plant Interaction for Older Adults. In Proceedings of the TEI '16: Tenth International Conference on Tangible, Embedded, and Embodied Interaction (TEI '16). ACM, New York, NY, USA, 373-379. DOI: https://doi.org/10.1145/2839462.2856548

Satoshi Kuribayashi and Akira Wakita. 2006. PlantDisplay: turning houseplants into ambient display. In Proceedings of the 2006 ACM SIGCHI international conference on Advances in computer entertainment technology(ACE '06). ACM, New York, NY, USA, Article 40 . DOI: https://doi.org/10.1145/1178823.1178871

Sijia TAO and Alain LIORET. 2016. Plant feedback on environmental changes and human interactions. In SIGGRAPH ASIA 2016 Posters (SA '16). ACM, New York, NY, USA, Article 21, 2 pages. DOI: https://doi.org/10.1145/3005274.3005327

Susan Loh and Yasu Santo. 2010. "Please touch the plant on your way up the stairs...": for OZCHI conference 2010. In Proceedings of the 22nd Conference of the Computer-Human Interaction Special Interest Group of Australia on Computer-Human Interaction (OZCHI '10). ACM, New York, NY, USA, 412-413. DOI: http://dx.doi.org/10.1145/1952222.1952321

Taiwoo Park, Tianyu Hu, and Jina Huh. 2016. Plant-based Games for Anxiety Reduction. In Proceedings of the 2016 Annual Symposium on Computer-Human Interaction in Play (CHI PLAY '16). ACM, New York, NY, USA, 199-204. DOI: https://doi.org/10.1145/2967934.2968094
