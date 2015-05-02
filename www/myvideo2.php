<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0 Transitional//EN">
<HTML>
<HEAD>
	<TITLE> Embedded video </TITLE>
	<SCRIPT LANGUAGE = "JavaScript">
	var videoPlaying = true;

	function toggleVideo( b )
	{
		videoPlaying = !videoPlaying;
		b.value = videoPlaying ? "Pause Video" : "Play Video";
		videoPlaying ? VideoPlayer.Play() : VideoPlayer.Pause();
	}
	</SCRIPT>
</HEAD>

<BODY>
	<H1> Thru an emberdded media player object </H1>
	<TABLE><TR>
	<TD>
		<OBJECT ID = "VideoPlayer" WIDTH = 200 HEIGHT = 225
		CLASSID = "CLSID:22D6F312-B0F6-11D0-94AB-0080C74C7E95">
		<PARAM NAME = "FileName" VALUE = "my30secvid.mp4">
		<PARAM NAME =  "AutoStart" VALUE = "true">
		<PARAM NAME = "ShowControls" VALUE = "false">
		<PARAM NAME = "Loop" VALUE = "true">
		</OBJECT> 
	</TD>
		<INPUT NAME = "video" TYPE = "button" VALUE = "Pause Video" ONCLICK = "toggleVideo( this )">
	</TABLE>
</BODY>
</HTML>

