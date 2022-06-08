//Custom script by Zeal to start the sabotage operation in Mission 2

class NO_SCR_OpSabotage_Action : NO_SCR_MissionSelectionAction
{
	
override void PerformAction(IEntity pOwnerEntity, IEntity pUserEntity)
		{
		
		super.PerformAction(pOwnerEntity, pUserEntity);
		
		//Finish initital task
		SCR_BaseTask task = SCR_BaseTask.Cast(GetGame().GetWorld().FindEntityByName("tsk_BlackOps_hub"));
		task.Finish();
		GetTaskManager().FinishTask(task);
		
		//Move waypoint
		vector travelToLocation = GetGame().GetWorld().FindEntityByName("tsk_main_C_0").GetOrigin();
        GetGame().GetWorld().FindEntityByName("WP").SetOrigin(travelToLocation);
		
		//Unlock next task
		NO_SCR_CoopTaskManager coopTM = NO_SCR_CoopTaskManager.Cast(GetTaskManager());
		coopTM.UnlockObjective("tsk_main_C_0_true");
		
		//Enables teleport trigger
		NO_SCR_PlayerTriggerEntity trigger = NO_SCR_PlayerTriggerEntity.Cast(GetGame().GetWorld().FindEntityByName("infil_C_trg"));
			if(trigger)
			trigger.SetActive(true);

		
	}

}