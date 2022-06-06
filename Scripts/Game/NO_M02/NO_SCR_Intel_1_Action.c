//Custom script by Zeal to pickup a intel piece in Mission 2

class NO_SCR_Intel_1_Action : ScriptedUserAction
{
	
	override void PerformAction(IEntity pOwnerEntity, IEntity pUserEntity)
		{
		
		//Finish initital task
		SCR_BaseTask task = SCR_BaseTask.Cast(GetGame().GetWorld().FindEntityByName("tsk_main_A_1"));
		task.Finish();
		GetTaskManager().FinishTask(task);
		
		//Unlock next task
		NO_SCR_CoopTaskManager coopTM = NO_SCR_CoopTaskManager.Cast(GetTaskManager());
		coopTM.UnlockObjective("tsk_main_A_2_true");
		
		//Spawns new assets & units
        NO_SCR_SpawnTrigger.Cast(GetGame().GetWorld().FindEntityByName("east_A_2_spawnTrg")).Spawn();
		NO_SCR_SpawnTrigger.Cast(GetGame().GetWorld().FindEntityByName("east_A_bonus_spawnTrg")).Spawn();
		
		//Move waypoint
		vector travelToLocation = GetGame().GetWorld().FindEntityByName("tsk_main_A_2").GetOrigin();
        GetGame().GetWorld().FindEntityByName("WP").SetOrigin(travelToLocation);
		
		//Removes intel piece
		SCR_EntityHelper.DeleteEntityAndChildren(pOwnerEntity);

	}

}