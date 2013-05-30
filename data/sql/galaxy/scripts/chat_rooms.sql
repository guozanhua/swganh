
/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET NAMES utf8 */;
/*!40014 SET FOREIGN_KEY_CHECKS=0 */;

DROP TABLE IF EXISTS `chat_rooms`;
CREATE TABLE `chat_rooms` (
	`room_id` INT(10) NOT NULL auto_increment,
	`is_private` TINYINT(1) UNSIGNED NOT NULL,
	`is_muted` TINYINT(1) UNSIGNED NOT NULL,
	`name` CHAR(50) NOT NULL DEFAULT '',
	`owner` BIGINT(20) NOT NULL,
	`creator` BIGINT(20) NOT NULL,
	`title` CHAR(255) NULL,
	PRIMARY KEY  (`room_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*!40000 ALTER TABLE `chat_rooms` DISABLE KEYS */;
/*!40000 ALTER TABLE `chat_rooms` ENABLE KEYS */;
/*!40014 SET FOREIGN_KEY_CHECKS=1 */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;