//Custom script by Zeal to pickup a intel piece in Mission 2

class NO_SCR_Intel_1_Action : ScriptedUserAction
{
	
	override void PerformAction(IEntity pOwnerEntity, IEntity pUserEntity)
		{
		
		//Finish initital task
		IEntity taskEntity1 = GetGame().GetWorld().FindEntityByName("tsk_main_A_1");
        NO_SCR_EditorTask task1 = NO_SCR_EditorTask.Cast(taskEntity1);
		task1.ChangeStateOfTask(TriggerType.Finish);
			
		//Unlock bonus task
		IEntity taskEntityB = GetGame().GetWorld().FindEntityByName("tsk_bonus_A");
        NO_SCR_EditorTask taskB = NO_SCR_EditorTask.Cast(taskEntityB);
		taskB.ChangeStateOfTask(TriggerType.Create);
		
		//Unlock next task
		IEntity taskEntity2 = GetGame().GetWorld().FindEntityByName("tsk_main_A_2");
        NO_SCR_EditorTask task2 = NO_SCR_EditorTask.Cast(taskEntity2);
		task2.ChangeStateOfTask(TriggerType.Assign);
		
		//Spawns new assets & units
        NO_SCR_SpawnTrigger.Cast(GetGame().GetWorld().FindEntityByName("east_A_2_spawnTrg")).Spawn();
		NO_SCR_SpawnTrigger.Cast(GetGame().GetWorld().FindEntityByName("east_A_bonus_spawnTrg")).Spawn();
		
		//Unlocks spawnpoint
		SCR_SpawnPoint.Cast(GetGame().GetWorld().FindEntityByName("spawnPoint_A_1")).SetFactionKey("US"); 
		
		//Removes intel piece
		SCR_EntityHelper.DeleteEntityAndChildren(pOwnerEntity);

	}

}