-- fix del 1er boss en templo de jade, no atacaba ni hacia nada ahora ya funciona
UPDATE `creature_template` SET `unit_flags`=0, `type_flags`=4 WHERE `entry` IN (56448);