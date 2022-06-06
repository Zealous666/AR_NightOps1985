//Custom script by Zeal to win the mission once the action is used

class NO_SCR_CaptureAction : ScriptedUserAction
{
	
	override void PerformAction(IEntity pOwnerEntity, IEntity pUserEntity)
		{
		
		SCR_BaseTask task = SCR_BaseTask.Cast(GetGame().GetWorld().FindEntityByName("tsk_main_3"));
		task.Finish();
		GetTaskManager().FinishTask(task);
		
		SCR_BaseGameMode gameMode = SCR_BaseGameMode.Cast(GetGame().GetGameMode()); // Get the game mode for the end script
        Faction faction = GetGame().GetFactionManager().GetFactionByKey("US"); // Get the winning faction Key
        int usIndex = GetGame().GetFactionManager().GetFactionIndex(faction); // Get the winning faction key's index
        gameMode.EndGameMode(SCR_GameModeEndData.CreateSimple(SCR_GameModeEndData.ENDREASON_EDITOR_FACTION_VICTORY, -1, usIndex)); // End the mission!
	}

}