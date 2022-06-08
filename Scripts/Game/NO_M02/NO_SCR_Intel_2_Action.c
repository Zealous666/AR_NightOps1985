//Custom script by Zeal to pickup a intel piece in Mission 2

class NO_SCR_Intel_2_Action : ScriptedUserAction
{
	
	override void PerformAction(IEntity pOwnerEntity, IEntity pUserEntity)
		{
		
		//Finish initital task
		SCR_BaseTask task = SCR_BaseTask.Cast(GetGame().GetWorld().FindEntityByName("tsk_main_A_2"));
		task.Finish();
		GetTaskManager().FinishTask(task);
		
		//Unlock next task
		NO_SCR_CoopTaskManager coopTM = NO_SCR_CoopTaskManager.Cast(GetTaskManager());
		coopTM.UnlockObjective("tsk_main_A_3_true");
		
		//Spawns new assets & units
        NO_SCR_SpawnTrigger.Cast(GetGame().GetWorld().FindEntityByName("east_A_X_spawnTrg")).Spawn();
		
		//Move waypoint
		vector travelToLocation = GetGame().GetWorld().FindEntityByName("tsk_main_A_X").GetOrigin();
        GetGame().GetWorld().FindEntityByName("WP").SetOrigin(travelToLocation);
		
		//Removes intel piece
		SCR_EntityHelper.DeleteEntityAndChildren(pOwnerEntity);
		
		//Enables exfil trigger
		NO_SCR_PlayerTriggerEntity trigger = NO_SCR_PlayerTriggerEntity.Cast(GetGame().GetWorld().FindEntityByName("exfil_A_trg"));
			if(trigger)
			trigger.SetActive(true);

	}

}