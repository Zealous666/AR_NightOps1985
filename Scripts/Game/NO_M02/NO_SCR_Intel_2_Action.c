//Custom script by Zeal to pickup a intel piece in Mission 2

class NO_SCR_Intel_2_Action : ScriptedUserAction
{
	
	override void PerformAction(IEntity pOwnerEntity, IEntity pUserEntity)
		{
		
		//Finish initital task
		IEntity taskEntity2 = GetGame().GetWorld().FindEntityByName("tsk_main_A_2");
        NO_SCR_EditorTask task2 = NO_SCR_EditorTask.Cast(taskEntity2);
		task2.ChangeStateOfTask(TriggerType.Finish);
		
		//Unlock next task
		IEntity taskEntityX = GetGame().GetWorld().FindEntityByName("tsk_main_A_X");
        NO_SCR_EditorTask taskX = NO_SCR_EditorTask.Cast(taskEntityX);
		taskX.ChangeStateOfTask(TriggerType.Assign);
		
		//Spawns new assets & units
        NO_SCR_SpawnTrigger.Cast(GetGame().GetWorld().FindEntityByName("east_A_03_spawnTrg")).Spawn();
		
		//Unlocks spawnpoint
		SCR_SpawnPoint.Cast(GetGame().GetWorld().FindEntityByName("spawnPoint_A_2")).SetFactionKey("US"); 
		
		//Removes intel piece
		SCR_EntityHelper.DeleteEntityAndChildren(pOwnerEntity);
		
		//Enables exfil trigger
		NO_SCR_PlayerTriggerEntity trigger = NO_SCR_PlayerTriggerEntity.Cast(GetGame().GetWorld().FindEntityByName("exfil_A_trg"));
			if(trigger)
			trigger.SetActive(true);

	}

}