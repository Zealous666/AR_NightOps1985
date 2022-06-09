//Custom script by Zeal to capture a vehicle as a objective via action

class NO_SCR_CaptureAction : ScriptedUserAction
{
	
	override void PerformAction(IEntity pOwnerEntity, IEntity pUserEntity)
		{
		
		//Finish current task
		SCR_BaseTask task = SCR_BaseTask.Cast(GetGame().GetWorld().FindEntityByName("tsk_main_3"));
		task.Finish();
		GetTaskManager().FinishTask(task);
		
		//Unlock exfil task
		NO_SCR_CoopTaskManager coopTM = NO_SCR_CoopTaskManager.Cast(GetTaskManager());
		coopTM.UnlockObjective("tsk_main_3_true");
		
		//Move waypoint
		vector travelToLocation = GetGame().GetWorld().FindEntityByName("tsk_main_x").GetOrigin();
        GetGame().GetWorld().FindEntityByName("WP").SetOrigin(travelToLocation);
		
		//Enables exfil scenario-end trigger
		NO_SCR_PlayerTriggerEntity trigger = NO_SCR_PlayerTriggerEntity.Cast(GetGame().GetWorld().FindEntityByName("tsk_main_x_trg"));
			if(trigger)
			trigger.SetActive(true);
		
		//Removes encryption key
		SCR_EntityHelper.DeleteEntityAndChildren(pOwnerEntity);
	}

}