//Custom script by Zeal to start the intel operation in Mission 2

class NO_SCR_OpIntel_Action : ScriptedUserAction
{
	
	override void PerformAction(IEntity pOwnerEntity, IEntity pUserEntity)
		{
		
		//Finish initital task
		SCR_BaseTask task = SCR_BaseTask.Cast(GetGame().GetWorld().FindEntityByName("tsk_hub_1"));
		task.Finish();
		GetTaskManager().FinishTask(task);
		
		//Move waypoint
		vector travelToLocation = GetGame().GetWorld().FindEntityByName("tsk_hub_2").GetOrigin();
        GetGame().GetWorld().FindEntityByName("WP").SetOrigin(travelToLocation);
		
		
		//De-Spawns the operation radio and shows the inactive radio placeholder
		//NO_SCR_SpawnTrigger.Cast(GetGame().GetWorld().FindEntityByName("opRadioSpawnTrg")).Despawn();
		//GenericEntity.Cast(GetGame().GetWorld().FindEntityByName("opRadioInactive")).Show(true);
		
		//Unlock next task
		NO_SCR_CoopTaskManager coopTM = NO_SCR_CoopTaskManager.Cast(GetTaskManager());
		coopTM.UnlockObjective("tsk_hub_2_true");
		
		//Enables teleport trigger
		NO_SCR_PlayerTriggerEntity trigger = NO_SCR_PlayerTriggerEntity.Cast(GetGame().GetWorld().FindEntityByName("infil_A_portTrg"));
			if(trigger)
			trigger.SetActive(true);

		
	}

}