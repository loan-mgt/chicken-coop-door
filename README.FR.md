# Porte de poulailler

### Changer la langue en :

  * <a href='https://github.com/Qypol342/chicken-coop-door/blob/master/README.md'> 🇬🇧 <a/>


 
## Fonctionnalité de la porte
 * 🌅 fermer au coucher du soleil -> baser sur lux
 * ⏰ ouvert à l'heure définie -> base sur l'horloge en temps réel
 * 🚪 disposition -> la corde empêche la porte de nuire à un poulet assis sur le chemin
 
 <img src="https://raw.githubusercontent.com/Qypol342/chicken-coop-door/master/coop_door_schema.png" alt="coop_door_schema" height="400">

## Matériel nécessaire
 * <a href='https://fr.banggood.com/DC-3V-6V-DC-1-120-Gear-Motor-TT-Motor-for-Smart-Car-Robot-DIY-p-1260117.html?p=C4290711027445201705&custlinkid=1586907'>Moteur (6v avec réduction de vitesse )<a/>
 * <a href='https://www.banggood.com/fr/Geekcreit-ATmega328P-Nano-V3-Controller-Board-Improved-Version-Module-Development-Board-p-940937.html?p=C4290711027445201705&custlinkid=1586907'>Arduino Nano<a/>
 * <a href='https://www.banggood.com/fr/50PCS-5MM-GL5516-Light-Dependent-Resistor-Photoresistor-LDR-p-1464084.html?p=C4290711027445201705&custlinkid=1586906'>Capteur de lumière (simple photorésistance)</a>
 * <a href='https://www.banggood.com/fr/DS3231-AT24C32-IIC-Precision-RTC-Real-Time-Clock-Memory-Module-p-1547989.html?p=C4290711027445201705&custlinkid=1586901' >Horloge en temps réel (DS3231)</a>
 * <a href='https://www.banggood.com/fr/Wholesale-L298N-Dual-H-Bridge-Stepper-Motor-Driver-Board-p-42826.html?p=C4290711027445201705&custlinkid=1586898'>Pont H (L298N)</a>
 
 Coût total de 27 euros

## Schéma de câblage

 <img src="https://raw.githubusercontent.com/Qypol342/chicken-coop-door/master/wiring%20diagram.png" alt="diagramme de câblage" width="800">

 
## Code
  * Vous devez d'abord configurer votre horloge en temps réel avec ce <a href='https://github.com/Qypol342/chicken-coop-door/blob/master/setclock.ino'>code</a>
  * Ensuite, vous pouvez télécharger le softwear de la porte, accessible <a href='https://github.com/Qypol342/chicken-coop-door/blob/master/coop_door_code.ino'>ici</a>
 

 
## Autonomie en énergie (Panneau Solaire)
  Je l'ai installé sur un panneau solaire en décembre 2020 et il fonctionne en continu depuis.
 
  J'utilise un panneau solaire de 50w et une vieille batterie de voiture.
 
  <a href='https://www.banggood.com/fr/10-or-20-or-30A-12-or-24V-LCD-Dual-USB-Solar-Panel-Battery-Regulator-Charge-Controller -p-1766616.html?cur_warehouse=ES&ID=554059&rmmds=search'>Voici</a> le contrôleur de charge que j'utilise, fournit 12v et 5v.

 
 
## ⚠️ Avis de non-responsabilité
 
 Le projet a été construit avec le composant que j'avais déjà, il est possible de trouver une pièce mieux adaptée pour ce projet.
 
 N'hésitez pas à ajouter un pull request ou à signaler un problème
