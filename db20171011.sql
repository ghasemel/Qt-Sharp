-- --------------------------------------------------------
-- Host:                         127.0.0.1
-- Server version:               5.7.19 - MySQL Community Server (GPL)
-- Server OS:                    Win64
-- HeidiSQL Version:             9.4.0.5174
-- --------------------------------------------------------

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET NAMES utf8 */;
/*!50503 SET NAMES utf8mb4 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;


-- Dumping database structure for sharpdb
DROP DATABASE IF EXISTS `sharpdb`;
CREATE DATABASE IF NOT EXISTS `sharpdb` /*!40100 DEFAULT CHARACTER SET utf8 COLLATE utf8_persian_ci */;
USE `sharpdb`;

-- Dumping structure for table sharpdb.tbl_coding_grp
DROP TABLE IF EXISTS `tbl_coding_grp`;
CREATE TABLE IF NOT EXISTS `tbl_coding_grp` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(100) COLLATE utf8_persian_ci NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8 COLLATE=utf8_persian_ci;

-- Dumping data for table sharpdb.tbl_coding_grp: ~0 rows (approximately)
DELETE FROM `tbl_coding_grp`;
/*!40000 ALTER TABLE `tbl_coding_grp` DISABLE KEYS */;
INSERT INTO `tbl_coding_grp` (`id`, `name`) VALUES
	(1, 'گروه 1'),
	(2, 'نتسایبمشس');
/*!40000 ALTER TABLE `tbl_coding_grp` ENABLE KEYS */;

/*!40101 SET SQL_MODE=IFNULL(@OLD_SQL_MODE, '') */;
/*!40014 SET FOREIGN_KEY_CHECKS=IF(@OLD_FOREIGN_KEY_CHECKS IS NULL, 1, @OLD_FOREIGN_KEY_CHECKS) */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
