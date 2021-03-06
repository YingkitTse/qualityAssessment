USE [master]
GO
/****** Object:  Database [StuTest]    Script Date: 2014/12/28 23:14:37 ******/
CREATE DATABASE [StuTest]
 CONTAINMENT = NONE
 ON  PRIMARY 
( NAME = N'StuTest', FILENAME = N'C:\Program Files\Microsoft SQL Server\MSSQL12.KITSQLSERVER\MSSQL\DATA\StuTest.mdf' , SIZE = 4288KB , MAXSIZE = UNLIMITED, FILEGROWTH = 1024KB )
 LOG ON 
( NAME = N'StuTest_log', FILENAME = N'C:\Program Files\Microsoft SQL Server\MSSQL12.KITSQLSERVER\MSSQL\DATA\StuTest_log.ldf' , SIZE = 1072KB , MAXSIZE = 2048GB , FILEGROWTH = 10%)
GO
ALTER DATABASE [StuTest] SET COMPATIBILITY_LEVEL = 100
GO
IF (1 = FULLTEXTSERVICEPROPERTY('IsFullTextInstalled'))
begin
EXEC [StuTest].[dbo].[sp_fulltext_database] @action = 'enable'
end
GO
ALTER DATABASE [StuTest] SET ANSI_NULL_DEFAULT OFF 
GO
ALTER DATABASE [StuTest] SET ANSI_NULLS OFF 
GO
ALTER DATABASE [StuTest] SET ANSI_PADDING OFF 
GO
ALTER DATABASE [StuTest] SET ANSI_WARNINGS OFF 
GO
ALTER DATABASE [StuTest] SET ARITHABORT OFF 
GO
ALTER DATABASE [StuTest] SET AUTO_CLOSE OFF 
GO
ALTER DATABASE [StuTest] SET AUTO_SHRINK OFF 
GO
ALTER DATABASE [StuTest] SET AUTO_UPDATE_STATISTICS ON 
GO
ALTER DATABASE [StuTest] SET CURSOR_CLOSE_ON_COMMIT OFF 
GO
ALTER DATABASE [StuTest] SET CURSOR_DEFAULT  GLOBAL 
GO
ALTER DATABASE [StuTest] SET CONCAT_NULL_YIELDS_NULL OFF 
GO
ALTER DATABASE [StuTest] SET NUMERIC_ROUNDABORT OFF 
GO
ALTER DATABASE [StuTest] SET QUOTED_IDENTIFIER OFF 
GO
ALTER DATABASE [StuTest] SET RECURSIVE_TRIGGERS OFF 
GO
ALTER DATABASE [StuTest] SET  ENABLE_BROKER 
GO
ALTER DATABASE [StuTest] SET AUTO_UPDATE_STATISTICS_ASYNC OFF 
GO
ALTER DATABASE [StuTest] SET DATE_CORRELATION_OPTIMIZATION OFF 
GO
ALTER DATABASE [StuTest] SET TRUSTWORTHY OFF 
GO
ALTER DATABASE [StuTest] SET ALLOW_SNAPSHOT_ISOLATION OFF 
GO
ALTER DATABASE [StuTest] SET PARAMETERIZATION SIMPLE 
GO
ALTER DATABASE [StuTest] SET READ_COMMITTED_SNAPSHOT OFF 
GO
ALTER DATABASE [StuTest] SET HONOR_BROKER_PRIORITY OFF 
GO
ALTER DATABASE [StuTest] SET RECOVERY FULL 
GO
ALTER DATABASE [StuTest] SET  MULTI_USER 
GO
ALTER DATABASE [StuTest] SET PAGE_VERIFY CHECKSUM  
GO
ALTER DATABASE [StuTest] SET DB_CHAINING OFF 
GO
ALTER DATABASE [StuTest] SET FILESTREAM( NON_TRANSACTED_ACCESS = OFF ) 
GO
ALTER DATABASE [StuTest] SET TARGET_RECOVERY_TIME = 0 SECONDS 
GO
ALTER DATABASE [StuTest] SET DELAYED_DURABILITY = DISABLED 
GO
USE [StuTest]
GO
/****** Object:  Table [dbo].[auth]    Script Date: 2014/12/28 23:14:37 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[auth](
	[no] [tinyint] NOT NULL,
	[name] [varchar](10) NOT NULL
) ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[cata]    Script Date: 2014/12/28 23:14:37 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[cata](
	[no] [tinyint] NULL,
	[name] [nchar](10) NULL
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[testInfo]    Script Date: 2014/12/28 23:14:37 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[testInfo](
	[id] [varchar](11) NOT NULL,
	[testName] [nchar](30) NOT NULL,
	[cata] [tinyint] NOT NULL,
	[mark] [tinyint] NOT NULL
) ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[userInfo]    Script Date: 2014/12/28 23:14:37 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[userInfo](
	[id] [varchar](11) NOT NULL,
	[name] [varchar](20) NOT NULL,
	[sex] [varchar](4) NULL,
	[age] [varchar](3) NULL,
	[pw] [varchar](50) NOT NULL,
	[auth] [tinyint] NOT NULL,
	[tel] [varchar](50) NULL,
	[address] [varchar](150) NULL,
 CONSTRAINT [PK__userInfo__3213E83FD03419B7] PRIMARY KEY CLUSTERED 
(
	[id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
/****** Object:  View [dbo].[usrInfoView]    Script Date: 2014/12/28 23:14:37 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE VIEW [dbo].[usrInfoView]
AS
SELECT   id, name, sex, age, tel, address
FROM      dbo.userInfo

GO
/****** Object:  StoredProcedure [dbo].[checkpw]    Script Date: 2014/12/28 23:14:37 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
-- =============================================
-- Author:		<Author,,Name>
-- Create date: <Create Date,,>
-- Description:	<Description,,>
-- =============================================
CREATE PROCEDURE [dbo].[checkpw] 
	-- Add the parameters for the stored procedure here
	@id char(11)
AS
BEGIN
	-- SET NOCOUNT ON added to prevent extra result sets from
	-- interfering with SELECT statements.
	SET NOCOUNT ON;

    -- Insert statements for procedure here
	SELECT pw,auth from userInfo where id=@id
END

GO
EXEC sys.sp_addextendedproperty @name=N'MS_DiagramPane1', @value=N'[0E232FF0-B466-11cf-A24F-00AA00A3EFFF, 1.00]
Begin DesignProperties = 
   Begin PaneConfigurations = 
      Begin PaneConfiguration = 0
         NumPanes = 4
         Configuration = "(H (1[40] 4[20] 2[20] 3) )"
      End
      Begin PaneConfiguration = 1
         NumPanes = 3
         Configuration = "(H (1 [50] 4 [25] 3))"
      End
      Begin PaneConfiguration = 2
         NumPanes = 3
         Configuration = "(H (1 [50] 2 [25] 3))"
      End
      Begin PaneConfiguration = 3
         NumPanes = 3
         Configuration = "(H (4 [30] 2 [40] 3))"
      End
      Begin PaneConfiguration = 4
         NumPanes = 2
         Configuration = "(H (1 [56] 3))"
      End
      Begin PaneConfiguration = 5
         NumPanes = 2
         Configuration = "(H (2 [66] 3))"
      End
      Begin PaneConfiguration = 6
         NumPanes = 2
         Configuration = "(H (4 [50] 3))"
      End
      Begin PaneConfiguration = 7
         NumPanes = 1
         Configuration = "(V (3))"
      End
      Begin PaneConfiguration = 8
         NumPanes = 3
         Configuration = "(H (1[56] 4[18] 2) )"
      End
      Begin PaneConfiguration = 9
         NumPanes = 2
         Configuration = "(H (1 [75] 4))"
      End
      Begin PaneConfiguration = 10
         NumPanes = 2
         Configuration = "(H (1[66] 2) )"
      End
      Begin PaneConfiguration = 11
         NumPanes = 2
         Configuration = "(H (4 [60] 2))"
      End
      Begin PaneConfiguration = 12
         NumPanes = 1
         Configuration = "(H (1) )"
      End
      Begin PaneConfiguration = 13
         NumPanes = 1
         Configuration = "(V (4))"
      End
      Begin PaneConfiguration = 14
         NumPanes = 1
         Configuration = "(V (2))"
      End
      ActivePaneConfig = 0
   End
   Begin DiagramPane = 
      Begin Origin = 
         Top = 0
         Left = 0
      End
      Begin Tables = 
         Begin Table = "userInfo"
            Begin Extent = 
               Top = 6
               Left = 38
               Bottom = 146
               Right = 180
            End
            DisplayFlags = 280
            TopColumn = 0
         End
      End
   End
   Begin SQLPane = 
   End
   Begin DataPane = 
      Begin ParameterDefaults = ""
      End
   End
   Begin CriteriaPane = 
      Begin ColumnWidths = 11
         Column = 1440
         Alias = 900
         Table = 1170
         Output = 720
         Append = 1400
         NewValue = 1170
         SortType = 1350
         SortOrder = 1410
         GroupBy = 1350
         Filter = 1350
         Or = 1350
         Or = 1350
         Or = 1350
      End
   End
End
' , @level0type=N'SCHEMA',@level0name=N'dbo', @level1type=N'VIEW',@level1name=N'usrInfoView'
GO
EXEC sys.sp_addextendedproperty @name=N'MS_DiagramPaneCount', @value=1 , @level0type=N'SCHEMA',@level0name=N'dbo', @level1type=N'VIEW',@level1name=N'usrInfoView'
GO
USE [master]
GO
ALTER DATABASE [StuTest] SET  READ_WRITE 
GO
